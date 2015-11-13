#include "syntaxique.hpp"
#include "monException.hpp"




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
		sysexp::modele::RegleAbstraite::PtrRegleAbstraite
		Syntaxique::parser(){
			declarations();
			return regles();
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

		sysexp::modele::RegleAbstraite::PtrRegleAbstraite 
		Syntaxique::regles(){
			sysexp::modele::RegleAbstraite::PtrRegleAbstraite regleSuiv;
			int i = 0;
			while(!precharge_.estFinFichier()){
				sysexp::modele::RegleAbstraite::PtrRegleAbstraite reglePrec = regle(i);
				reglePrec->ajouterSuccesseur(regleSuiv);
				regleSuiv = reglePrec;
				i++;
				if (!precharge_.estFinExpression())
					throw MonException(lexical_,"attendu: ';'");
				suivant();
			}
			return regleSuiv;
		}

		sysexp::modele::RegleAbstraite::PtrRegleAbstraite
		Syntaxique::regle(int i){
			if(precharge_.estSi()){
				return regle_avec_premisse(i);
			}
			else{
				return regle_sans_premisse(i);
			}
		}

		sysexp::modele::RegleSansPremisse::PtrRegleAbstraite 
		Syntaxique::regle_sans_premisse(int i){
			sysexp::modele::RegleSansPremisse::PtrRegleAbstraite regle(new sysexp::modele::RegleSansPremisse(i, conclusion()));
			return regle;		
		}

		sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion 
		Syntaxique::conclusion(){
			// retourner la conclusion contruite
			if(precharge_.estIdentificateur()){
				std::map<std::string, std::string>::iterator it = faits_.find(precharge_.lireRepresentation());
				if(it == faits_.end()){
					throw MonException(lexical_, "le fait n'a pas été declare");
				}
				else if(it->second == "booleen"){
					return conclusion_booleenne();
				}
				else if(it->second == "symbolique"){
					return conclusion_symbolique();
				}
				else if(it->second == "entier"){
					return conclusion_entiere();
				}
			}
			else if(precharge_.estNon()){
				return conclusion_booleenne();
			}
			throw MonException(lexical_, "attendu: un identificateur ou un 'non'");
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

		sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion
		Syntaxique::conclusion_entiere(){
			Jeton ent = precharge_;
			// la conclusion sera probablement construite ici.
			suivant();
			if(!precharge_.estEgal()){
				throw MonException(lexical_, "attendu: '='");
			}
			suivant();
			sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion(new sysexp::modele::FormeConclusionEntierExpression(ent.lireRepresentation(), expressionEntiere()));
			return conclusion;
		}

		sysexp::modele::ValeurAbstraite::PtrValeur 
		Syntaxique::expressionEntiere(){
			sysexp::modele::ValeurAbstraite::PtrValeur facteur_g;
			if(precharge_.estOperateurPlus()){
				suivant();
				facteur_g = terme();
			} 
			else if(precharge_.estOperateurMoins()){
				suivant();
				sysexp::modele::FeuilleConstante::PtrFeuilleConstante f(new sysexp::modele::FeuilleConstante(0));
				facteur_g = terme();
				sysexp::modele::OperateurMoins::PtrOperateurMoins opm(new sysexp::modele::OperateurMoins(f, facteur_g));
			}
			else{
				facteur_g = terme();
			}
			while(precharge_.estOperateurPlus() || precharge_.estOperateurMoins()){
				if(precharge_.estOperateurPlus()){
					suivant();
					sysexp::modele::ValeurAbstraite::PtrValeur facteur_d = terme();
					sysexp::modele::OperateurPlus::PtrOperateurPlus oppl(new sysexp::modele::OperateurPlus(facteur_g, facteur_d));
					facteur_g = oppl;
				}
				if(precharge_.estOperateurMoins()){
					suivant();
					sysexp::modele::ValeurAbstraite::PtrValeur facteur_d = terme();
					sysexp::modele::OperateurMoins::PtrOperateurMoins opm(new sysexp::modele::OperateurMoins(facteur_g, facteur_d));
					facteur_g = opm;
				}
			}
			return facteur_g;
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
			return facteur_g;
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
					sysexp::modele::ValeurAbstraite::PtrValeur expr = expressionEntiere();
					if(!precharge_.estParentheseFermante()){
						throw MonException(lexical_, "attendu : ')'");
					}
					suivant();
					return expr;
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

		sysexp::modele::RegleAvecPremisse::PtrRegleAbstraite
		Syntaxique::regle_avec_premisse(int i){
			suivant();
			std::list<sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse>  premisses = condition();
			if(!precharge_.estAlors()){
				throw MonException(lexical_, "attendu: 'alors'");
			}
			suivant();
			sysexp::modele::RegleAvecPremisse::PtrRegleAvecPremisse regle( new sysexp::modele::RegleAvecPremisse(i, conclusion()));
			for(std::list<sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse>::iterator it = premisses.begin(); it != premisses.end(); ++it){
    			regle->ajouterPremisse(*it);
    		}
			return regle;
		}

		std::list<sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse> 
		Syntaxique::condition(){
			std::list<sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse> premisses;
			premisses.push_back(premisse());
			while(precharge_.estEt()){
				suivant();
				premisses.push_back(premisse());

			}
			return premisses;
		}

		sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse
		Syntaxique::premisse(){
			if(precharge_.estIdentificateur()){
				std::map<std::string, std::string>::iterator it = faits_.find(precharge_.lireRepresentation());
				if(it == faits_.end()){
					throw MonException(lexical_, "le fait n'a pas été declare");
				}
				else if(it->second == "booleen"){
					return premisse_booleenne();
				}
				else if(it->second == "symbolique"){
					return premisse_symbolique();
				}
				else if(it->second == "entier"){
					return premisse_entiere();
				}
			}
			else if(precharge_.estNon()){
				return premisse_booleenne();
			}
			else{
				throw MonException(lexical_, "attendu: un identificateur ou un 'non'");
			}
		}

		sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse
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
				sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse(new sysexp::modele::FormePremisseBoolFalse(it->first));
				suivant();
				return premisse;
			}
			else{
				sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse(new sysexp::modele::FormePremisseBoolTrue(precharge_.lireRepresentation()));
				suivant();
				return premisse;
			}
		}
		

		sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse
		Syntaxique::premisse_symbolique(){
			Jeton symb = precharge_;
			suivant();
			if(!precharge_.estEgal() && !precharge_.estDifferent()){
				throw MonException(lexical_, "attendu: '=' ou '/='");
			}
			Jeton signe = precharge_; 
			suivant();
			
			if(!precharge_.estIdentificateur()){
					throw MonException(lexical_, "attendu : identificateur");
			}
			
			std::map<std::string, std::string>::iterator it = faits_.find(precharge_.lireRepresentation());
			if(it == faits_.end()){
				if(signe.estEgal()){
					sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new sysexp::modele::FormePremisseSymboliqueConstante(symb.lireRepresentation(), sysexp::modele::compEqualEqual, precharge_.lireRepresentation()));
					suivant();
					return premisse;
				}

				else if(signe.estDifferent()){
					sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new sysexp::modele::FormePremisseSymboliqueConstante(symb.lireRepresentation(), sysexp::modele::compDiff, precharge_.lireRepresentation()));
					suivant();
					return premisse;
				}
			}
			else{ 
				if(it->second != "symbolique"){
					throw MonException(lexical_, "le fait n'est pas symbolique");
				}
				if(signe.estEgal()){
					sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new sysexp::modele::FormePremisseSymboliqueConstante(symb.lireRepresentation(), sysexp::modele::compEqualEqual, it->first));
					suivant();
					return premisse;
				}

				else if(signe.estDifferent()){
					sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new sysexp::modele::FormePremisseSymboliqueConstante(symb.lireRepresentation(), sysexp::modele::compDiff, it->first));
					suivant();
					return premisse;
				}
			}
		}

		sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse
		Syntaxique::premisse_entiere(){
			Jeton ent = precharge_;
			suivant();
			if(!precharge_.estEgal() && !precharge_.estSuperieur() && !precharge_.estInferieur() &&
				!precharge_.estSupEgal() && !precharge_.estInfEgal() && !precharge_.estDifferent()){
				throw MonException(lexical_, "attendu : '=' ou '/=' ou '<' ou '>' ou '<=' ou '>='");
			}
			Jeton signe = precharge_;
			if(signe.estEgal()){
				suivant();
				sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new sysexp::modele::FormePremisseEntierExpression(ent.lireRepresentation(), sysexp::modele::compEqualEqual, expressionEntiere()));
				return premisse;
			}
			else if(signe.estSuperieur()){
				suivant();
				sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new sysexp::modele::FormePremisseEntierExpression(ent.lireRepresentation(), sysexp::modele::compSup, expressionEntiere()));
				return premisse;
			}
			else if(signe.estInferieur()){
				suivant();
				sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new sysexp::modele::FormePremisseEntierExpression(ent.lireRepresentation(), sysexp::modele::compLess, expressionEntiere()));
				return premisse;			
			}
			else if(signe.estSupEgal()){
				suivant();
				sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new sysexp::modele::FormePremisseEntierExpression(ent.lireRepresentation(), sysexp::modele::compSupEqual, expressionEntiere()));
				return premisse;
			}
			else if(signe.estInfEgal()){
				suivant();
				sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new sysexp::modele::FormePremisseEntierExpression(ent.lireRepresentation(), sysexp::modele::compLessEqual, expressionEntiere()));
				return premisse;
			}
			else if(signe.estDifferent()){
				suivant();
				sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new sysexp::modele::FormePremisseEntierExpression(ent.lireRepresentation(), sysexp::modele::compDiff, expressionEntiere()));
				return premisse;
			}
		}
	}
}
