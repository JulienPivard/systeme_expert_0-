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
				throw MonException(lexical_, "expected 'faits_booleens'");
			precharge_ = lexical_.suivant();
			listeFaits("booleen");
		}
		

		void
	 	Syntaxique::declarations_symb(){
	 		if(!precharge_.estFaitSymb())
				throw MonException(lexical_,"expected 'faits_symboliques'");
			precharge_ = lexical_.suivant();
			listeFaits("symbolique");	
		}

		void
		Syntaxique::declarations_ent(){
			if(!precharge_.estFaitEnt())
				throw MonException(lexical_, "expected 'faits_entiers'");
			precharge_ = lexical_.suivant();
			listeFaits("entier");	
		}

		void
		Syntaxique::listeFaits(std::string valeur){
			if (!precharge_.estEgal())
				throw MonException(lexical_, "expected '='");
			precharge_ = lexical_.suivant();

			while(!precharge_.estFinExpression()){
				if(!precharge_.estIdentificateur())
					throw MonException(lexical_, "expected un mot contenant des lettres ou des chiffres ou un  '_'");
				faits_[precharge_.lireRepresentation()] =valeur;
				precharge_ = lexical_.suivant();

				if(precharge_.estFinExpression()){
					precharge_ = lexical_.suivant();
					break;
				}
				if (!precharge_.estSeparateur())
					throw MonException(lexical_,"expected ','");
				precharge_ = lexical_.suivant();
			}
		}

		void 
		Syntaxique::regles(){
			while(!precharge_.estFinExpression()){
				regle();
			}
		}

		void
		Syntaxique::regle(){
			if(precharge_.estSi()){
				regle_avec_premisse();
			}
			regle_sans_premisse();
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

		}

		void
		Syntaxique::conclusion_symbolique(){

		}

void
		Syntaxique::conclusion_entiere(){

		}


		void
		Syntaxique::regle_avec_premisse(){

		}
	}
}
