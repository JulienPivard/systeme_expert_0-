#include "syntaxique.hpp"
#include "monException.hpp"
#include <iostream>


namespace sysexp{

	 namespace builders{
		 
		 Syntaxique::Syntaxique(Lexical & lexical):
			lexical_(lexical),
			precharge_(lexical_.suivant())
			{}
		
		 const Lexical	
		 Syntaxique::lireLexical(){
			 return lexical_;
		 }
			
		void
		Syntaxique::suivant(){
			precharge_ = lexical_.suivant();
			
		}
		void
		Syntaxique::parser(){
			declarations();
			for(const std::pair< std::string, std::string > & couple : faits_){
				std::cout << couple.first << " " << couple.second << std::endl;
			}
			regles();
		}

		void 
		Syntaxique::declarations(){
			declarations_bool();
			declarations_symb();
			declarations_ent();
		}

		void 
		Syntaxique::declarations_bool(){

			if(!precharge_.estFaitBool())
				throw MonException(lexical_, "attendu: 'faits_booleens'");
			suivant();
			listeFaits("booleen");
		}
		

		void
	 	Syntaxique::declarations_symb(){
	 		if(!precharge_.estFaitSymb())
				throw MonException(lexical_,"attendu: 'faits_symboliques'");
			suivant();
			listeFaits("symbolique");	
		}

		void
		Syntaxique::declarations_ent(){
			if(!precharge_.estFaitEnt())
				throw MonException(lexical_, "attendu: 'faits_entiers'");
			suivant();
			listeFaits("entier");	
		}

		void
		Syntaxique::listeFaits(std::string valeur){
			if (!precharge_.estEgal())
				throw MonException(lexical_, "attendu: '='");
			suivant();

			while(!precharge_.estFinExpression()){
				if(!precharge_.estIdentificateur())
					throw MonException(lexical_, "attendu: un identificateur ou un '_'");
				faits_[precharge_.lireRepresentation()] = valeur;
				suivant();

				if(precharge_.estFinExpression()){
					suivant();
					break;
				}
				if (!precharge_.estSeparateur())
					throw MonException(lexical_,"attendu: ','");
				suivant();
			}
		}

		void 
		Syntaxique::regles(){
			while(!precharge_.estFinFichier()){
				regle();
				if (!precharge_.estFinExpression())
					throw MonException(lexical_,"attendu: ';'");
				suivant();
			}
		}

		void
		Syntaxique::regle(){
			if(precharge_.estSi()){
				regle_avec_premisse();
			}
			else{
				regle_sans_premisse();
			}
		}

		void 
		Syntaxique::regle_sans_premisse(){
			conclusion();
		}

		void 
		Syntaxique::conclusion(){
			if(precharge_.estIdentificateur()){
				std::map<std::string, std::string>::iterator it = faits_.find(precharge_.lireRepresentation());
				if(it == faits_.end()){
					throw MonException(lexical_, "le fait n'a pas été declare");
				}
				else if(it->second == "booleen"){
					conclusion_booleenne();
				}
				else if(it->second == "symbolique"){
					conclusion_symbolique();
				}
				else if(it->second == "entier"){
					conclusion_entiere();
				}
			}
			else if(precharge_.estNon()){
				conclusion_booleenne();
			}
			else{
				throw MonException(lexical_, "attendu: un identificateur ou un 'non'");
			}
		}

		void
		Syntaxique::conclusion_booleenne(){
			if(precharge_.estNon()){
				suivant();
				if(!precharge_.estIdentificateur()){
					throw MonException(lexical_, "attendu: un fait booléen");
				}
				std::map<std::string, std::string>::iterator it = faits_.find(precharge_.lireRepresentation());
				if(it == faits_.end()){
					throw MonException(lexical_, "le fait n'a pas été declare");
				}
				else if(it->second != "booleen"){
					throw MonException(lexical_, "le fait n'est pas booléen");
				}
				// tout se passe bien ! 
				suivant();
			}
			else{
				// tout se passe bien ! 
				suivant();
			}
		}
	
		void
		Syntaxique::conclusion_symbolique(){
			suivant();
			if(!precharge_.estEgal()){
				throw MonException(lexical_, "attendu '='");
			}
			suivant();
			
			if(!precharge_.estIdentificateur()){
					throw MonException(lexical_, "attendu : identificateur");
			}
			
			std::map<std::string, std::string>::iterator it = faits_.find(precharge_.lireRepresentation());
			if(it == faits_.end()){

				//tout se passe bien ! 
				suivant();
			}
			else{ 
				if(it->second != "symbolique"){
					throw MonException(lexical_, "le fait n'est pas symbolique");
				}
				//tout se passe bien
				suivant();
			}
		}

		void
		Syntaxique::conclusion_entiere(){
			suivant();
			if(!precharge_.estEgal()){
				throw MonException(lexical_, "attendu: '='");
			}
			suivant();
			expressionEntiere();

		}

		void 
		Syntaxique::expressionEntiere(){
			if(precharge_.estOperateurPlus() || precharge_.estOperateurMoins()){
				suivant();
			}
			terme();
			while(precharge_.estOperateurPlus() || precharge_.estOperateurMoins()){
				suivant();
				terme();
			}
		}

		void
		Syntaxique::terme(){
			facteur();
			while(precharge_.estOperateurMul() || precharge_.estOperateurDiv()){
				suivant();
				facteur();
			}

		}

		void
		Syntaxique::facteur(){
			std::map<std::string, std::string>::iterator it = faits_.find(precharge_.lireRepresentation());
			if(it == faits_.end()){
				if(precharge_.estEntier()){
					//tout se passe bien ! 
					suivant();
				}
				else if(precharge_.estParentheseOuvrante()){
					//tout se passe bien ! 
					suivant();
					expressionEntiere();
					if(!precharge_.estParentheseFermante()){
						throw MonException(lexical_, "attendu : ')'");
					}
					suivant();
				}
				else{
					throw MonException(lexical_, "attendu : un entier ou '('");
				}	
			}
			else{ 
				if(it->second != "entier"){
					throw MonException(lexical_, "le fait n'est pas entier");
				}
				// tout se passe bien
				suivant();

			}

		}
		void
		Syntaxique::regle_avec_premisse(){
			suivant();
			condition();
			if(!precharge_.estAlors()){
				throw MonException(lexical_, "attendu: 'alors'");
			}
			suivant();
			conclusion();
		}

		void 
		Syntaxique::condition(){
			premisse();
			while(precharge_.estEt()){
				suivant();
				premisse();

			}
		}

		void
		Syntaxique::premisse(){
			if(precharge_.estIdentificateur()){
				std::map<std::string, std::string>::iterator it = faits_.find(precharge_.lireRepresentation());
				if(it == faits_.end()){
					throw MonException(lexical_, "le fait n'a pas été declare");
				}
				else if(it->second == "booleen"){
					premisse_booleenne();
				}
				else if(it->second == "symbolique"){
					premisse_symbolique();
				}
				else if(it->second == "entier"){
					premisse_entiere();
				}
			}
			else if(precharge_.estNon()){
				premisse_booleenne();
			}
			else{
				throw MonException(lexical_, "attendu: un identificateur ou un 'non'");
			}
		}

		void
		Syntaxique::premisse_booleenne(){
			if(precharge_.estNon()){
				suivant();
				if(!precharge_.estIdentificateur()){
					throw MonException(lexical_, "attendu: un fait booléen");
				}
				std::map<std::string, std::string>::iterator it = faits_.find(precharge_.lireRepresentation());
				if(it == faits_.end()){
					throw MonException(lexical_, "le fait n'a pas été declare");
				}
				else if(it->second != "booleen"){
					throw MonException(lexical_, "le fait n'est pas booléen");
				}
				// tout se passe bien ! 
				suivant();
			}
			else{
				// tout se passe bien ! 
				suivant();
			}
		}
		

		void
		Syntaxique::premisse_symbolique(){
			suivant();
			if(!precharge_.estEgal() && !precharge_.estDifferent()){
				throw MonException(lexical_, "attendu: '=' ou '/='");
			}
			suivant();
			
			if(!precharge_.estIdentificateur()){
					throw MonException(lexical_, "attendu : identificateur");
			}
			
			std::map<std::string, std::string>::iterator it = faits_.find(precharge_.lireRepresentation());
			if(it == faits_.end()){

				//tout se passe bien ! 
				suivant();
			}
			else{ 
				if(it->second != "symbolique"){
					throw MonException(lexical_, "le fait n'est pas symbolique");
				}
				//tout se passe bien
				suivant();
			}
		}

		void
		Syntaxique::premisse_entiere(){
			suivant();
			if(!precharge_.estEgal() && !precharge_.estSuperieur() && !precharge_.estInferieur() &&
				!precharge_.estSupEgal() && !precharge_.estInfEgal() && !precharge_.estDifferent()){
				throw MonException(lexical_, "attendu : '=' ou '/=' ou '<' ou '>' ou '<=' ou '>='");
			}
			suivant();
			expressionEntiere();
		}

	}
}
