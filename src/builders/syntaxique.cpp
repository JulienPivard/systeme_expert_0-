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
			// base de regle, , attention on a besoin de la regle precedente ! 
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
			// construire la regle
		}

		void 
		Syntaxique::conclusion(){
			// retourner la conclusion contruite
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

		sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion
		Syntaxique::conclusion_booleenne(){
			// retourner la conslusion constuite
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
				sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion(new sysexp::modele::FormeConclusionBoolFalse(it->first)); 
				suivant();
				return conclusion;
			}
			else{
				sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion(new sysexp::modele::FormeConclusionBoolTrue(precharge_.lireRepresentation())); 
				suivant();
				return conclusion;
			}
		}
	
		sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion
		Syntaxique::conclusion_symbolique(){
			// retourner la conclusion construite 
			Jeton symb = precharge_ ; 
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

				sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion(new sysexp::modele::FormeConclusionSymboliqueConstante(symb.lireRepresentation(), precharge_.lireRepresentation()));
				suivant();
				return conclusion;
			}
			else{ 
				if(it->second != "symbolique"){
					throw MonException(lexical_, "le fait n'est pas symbolique");
				}
				sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion(new sysexp::modele::FormeConclusionSymboliqueConstante(symb.lireRepresentation(), it->first));
				suivant();
				return conclusion;
			}
		}

		void
		Syntaxique::conclusion_entiere(){
			// la conclusion sera probablement construite ici.
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

		sysexp::modele::ValeurAbstraite::PtrValeur
		Syntaxique::terme(){
			sysexp::modele::ValeurAbstraite::PtrValeur facteur_g = facteur();
			while(precharge_.estOperateurMul() || precharge_.estOperateurDiv()){
				if(precharge_.estOperateurMul()){
					suivant();
					sysexp::modele::ValeurAbstraite::PtrValeur facteur_d = facteur();
					sysexp::modele::OperateurMul::PtrOperateurMul opmul(new sysexp::modele::OperateurMul(facteur_g, facteur_d));
					facteur_g = opmul;
				}
				if(precharge_.estOperateurDiv()){
					suivant();
					sysexp::modele::ValeurAbstraite::PtrValeur facteur_d = facteur();
					sysexp::modele::OperateurDiv::PtrOperateurDiv opd(new sysexp::modele::OperateurDiv(facteur_g, facteur_d));
					facteur_g = opd;
				}
			}
		}

		sysexp::modele::ValeurAbstraite::PtrValeur
		Syntaxique::facteur(){ 
			std::map<std::string, std::string>::iterator it = faits_.find(precharge_.lireRepresentation());
			if(it == faits_.end()){
				if(precharge_.estEntier()){
					sysexp::modele::FeuilleConstante::PtrFeuilleConstante val(new sysexp::modele::FeuilleConstante(std::stoi(precharge_.lireRepresentation())));
					suivant();
					return val;
				}
				else if(precharge_.estParentheseOuvrante()){
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
				sysexp::modele::FeuilleFait::PtrFeuilleFait val(new sysexp::modele::FeuilleFait(it->first));
				suivant();
				return val;	
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
			// construire la regle et la retourner
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
			// retourner la premisse
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
				// premisse bool false
				suivant();
			}
			else{
				// premisse bool true
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

				//premisse symb constante
				suivant();
			}
			else{ 
				if(it->second != "symbolique"){
					throw MonException(lexical_, "le fait n'est pas symbolique");
				}
				//premisse symb fait
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
			// premisse entiere
		}

	}
}
