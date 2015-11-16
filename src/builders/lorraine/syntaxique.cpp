#include "syntaxique.hpp"
#include "monException.hpp"

// on utilise using namespace ici 
// pour pas que la créations des objets prenne 3 kilometres de long 
// et qu'on s'y retrouve quand on lit le code
using namespace sysexp::modele;
namespace sysexp{

	 namespace builders{

	 	namespace lorraine{

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
			RegleAbstraite::PtrRegleAbstraite
			Syntaxique::parser(){
				// pour avoir une base de règle il faut parser les déclarations et les règles.
				declarations();
				return regles();
			}

			void
			Syntaxique::declarations(){
				// il y a trois types de déclarations.
				declarations_bool();
				declarations_symb();
				declarations_ent();
			}

			void
			Syntaxique::declarations_bool(){
				// on regarde si on est dans les déclarations booléennes.
				if(!precharge_.estFaitBool())
					throw MonException(lexical_, "attendu: 'faits_booleens'");
				suivant();
				// on construit la map contenant un fait et son type.
				listeFaits("booleen");
			}


			void
		 	Syntaxique::declarations_symb(){
		 		// on regarde si on est dans les déclarations symboliques.
		 		if(!precharge_.estFaitSymb())
					throw MonException(lexical_,"attendu: 'faits_symboliques'");
				suivant();
				// on construit la map contenant un fait et son type.
				listeFaits("symbolique");
			}

			void
			Syntaxique::declarations_ent(){
				// on regarde si on est dans les déclarations entières
				if(!precharge_.estFaitEnt())
					throw MonException(lexical_, "attendu: 'faits_entiers'");
				suivant();
				// on construit la map contenant un fait et son type.
				listeFaits("entier");
			}

			void
			Syntaxique::listeFaits(std::string valeur){
				// on regarde si la structure des déclarations est bien respectée.
				// une déclaration est de la forme "faits_type = liste_de_faits_séparés_par_une_virgule ;"
				if (!precharge_.estEgal())
					throw MonException(lexical_, "attendu: '='");
				suivant();

				while(!precharge_.estFinExpression()){
					if(!precharge_.estIdentificateur())
						throw MonException(lexical_, "attendu: un identificateur ou un '_'");
					// ici on ajoute le fait et son type à la map.
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

			RegleAbstraite::PtrRegleAbstraite
			Syntaxique::regles(){
				// apres avoir parsé les déclarations, il nous reste que des regles.
				// pour créer la base de regle on a besoin d'une regle pour la chainer a son successeur.
				RegleAbstraite::PtrRegleAbstraite regleSuiv;
				int i = 0;
				while(!precharge_.estFinFichier()){
					RegleAbstraite::PtrRegleAbstraite reglePrec = regle(i);
					reglePrec->ajouterSuccesseur(regleSuiv);
					regleSuiv = reglePrec;
					i++;
					if (!precharge_.estFinExpression())
						throw MonException(lexical_,"attendu: ';'");
					suivant();
				}
				return regleSuiv;
			}

			RegleAbstraite::PtrRegleAbstraite
			Syntaxique::regle(int i){
				// une règle est soit sans prémisse, soit avec prémisse.
				if(precharge_.estSi()){
					return regle_avec_premisse(i);
				}
				else{
					return regle_sans_premisse(i);
				}
			}

			RegleSansPremisse::PtrRegleAbstraite
			Syntaxique::regle_sans_premisse(int i){
				// une règle sans prémisse est uniquement composée d'une conclusion.
				RegleSansPremisse::PtrRegleAbstraite regle(new RegleSansPremisse(i, conclusion() ));
				return regle;
			}

			FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion
			Syntaxique::conclusion(){
				// une conclusion peut être booléenne, symbolique ou entière.
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

			FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion
			Syntaxique::conclusion_booleenne(){
				// une conclusion booléenne est constituée soit d'un fait_booléen ou de "non" fait_booléen.
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
					FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion(new FormeConclusionBoolFalse(it->first));
					suivant();
					return conclusion;
				}
				else{
					FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion(new FormeConclusionBoolTrue(precharge_.lireRepresentation()));
					suivant();
					return conclusion;
				}
			}

			FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion
			Syntaxique::conclusion_symbolique(){
				// une conclusion symbolique est de la forme fait_symb = (fait_sybm || constante_symb).
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

					FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion(new FormeConclusionSymboliqueConstante(symb.lireRepresentation(), precharge_.lireRepresentation()));
					suivant();
					return conclusion;
				}
				else{
					if(it->second != "symbolique"){
						throw MonException(lexical_, "le fait n'est pas symbolique");
					}
					FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion(new FormeConclusionSymboliqueConstante(symb.lireRepresentation(), it->first));
					suivant();
					return conclusion;
				}
			}

			FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion
			Syntaxique::conclusion_entiere(){
				// une conclusion entière est composée d'un fait entier d'un = et d'une expression entière.
				Jeton ent = precharge_;
				suivant();
				if(!precharge_.estEgal()){
					throw MonException(lexical_, "attendu: '='");
				}
				suivant();
				FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion(new FormeConclusionEntierExpression(ent.lireRepresentation(), expressionEntiere()));
				return conclusion;
			}

			ValeurAbstraite::PtrValeur
			Syntaxique::expressionEntiere(){
				// une expression est composée de (+||-)(terme)[(+||-)(terme)]*
				ValeurAbstraite::PtrValeur facteur_g;
				if(precharge_.estOperateurPlus()){
					suivant();
					facteur_g = terme();
				}
				else if(precharge_.estOperateurMoins()){
					suivant();
					FeuilleConstante::PtrFeuilleConstante f(new FeuilleConstante(0));
					facteur_g = terme();
					OperateurMoins::PtrOperateurMoins opm(new OperateurMoins(f, facteur_g));
	                facteur_g = opm;
				}
				else{
					facteur_g = terme();
				}
				while(precharge_.estOperateurPlus() || precharge_.estOperateurMoins()){
					if(precharge_.estOperateurPlus()){
						suivant();
						ValeurAbstraite::PtrValeur facteur_d = terme();
						OperateurPlus::PtrOperateurPlus oppl(new OperateurPlus(facteur_g, facteur_d));
						facteur_g = oppl;
					}
					if(precharge_.estOperateurMoins()){
						suivant();
						ValeurAbstraite::PtrValeur facteur_d = terme();
						OperateurMoins::PtrOperateurMoins opm(new OperateurMoins(facteur_g, facteur_d));
						facteur_g = opm;
					}
				}
				return facteur_g;
			}

			ValeurAbstraite::PtrValeur
			Syntaxique::terme(){
				// un terme est composé d'un facteur (x facteur)*
				ValeurAbstraite::PtrValeur facteur_g = facteur();
				while(precharge_.estOperateurMul() || precharge_.estOperateurDiv()){
					if(precharge_.estOperateurMul()){
						suivant();
						ValeurAbstraite::PtrValeur facteur_d = facteur();
						OperateurMul::PtrOperateurMul opmul(new OperateurMul(facteur_g, facteur_d));
						facteur_g = opmul;
					}
					if(precharge_.estOperateurDiv()){
						suivant();
						ValeurAbstraite::PtrValeur facteur_d = facteur();
						OperateurDiv::PtrOperateurDiv opd(new OperateurDiv(facteur_g, facteur_d));
						facteur_g = opd;
					}
				}
				return facteur_g;
			}

			ValeurAbstraite::PtrValeur
			Syntaxique::facteur(){
				// un facteur est composé d'une constante entiere, d'un fait entier ou d'une expression entiere entre parenthèse.
				std::map<std::string, std::string>::iterator it = faits_.find(precharge_.lireRepresentation());
				if(it == faits_.end()){
					if(precharge_.estEntier()){
						FeuilleConstante::PtrFeuilleConstante val(new FeuilleConstante(std::stoi(precharge_.lireRepresentation())));
						suivant();
						return val;
					}
					else if(precharge_.estParentheseOuvrante()){
						suivant();
						ValeurAbstraite::PtrValeur expr = expressionEntiere();
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
					FeuilleFait::PtrFeuilleFait val(new FeuilleFait(it->first));
					suivant();
					return val;
				}
			}

			RegleAvecPremisse::PtrRegleAbstraite
			Syntaxique::regle_avec_premisse(int i){
				// une regle avec prémisse est constituée d'un si suivi d'une condition d'un alors et d'une conclusion.
				suivant();
				std::list<FormeAbstraitePremisse::PtrFormeAbstraitePremisse>  premisses = condition();
				if(!precharge_.estAlors()){
					throw MonException(lexical_, "attendu: 'alors'");
				}
				suivant();
	            // On chope le premier element.
				RegleAvecPremisse::PtrRegleAvecPremisse regle( new RegleAvecPremisse(i, premisses.front(), conclusion() ));
				for(std::list<FormeAbstraitePremisse::PtrFormeAbstraitePremisse>::iterator it = premisses.begin()++; it != premisses.end(); ++it){
	    			regle->ajouterPremisse(*it);
	    		}
				return regle;
			}

			std::list<FormeAbstraitePremisse::PtrFormeAbstraitePremisse>
			Syntaxique::condition(){
				// contition (et condition)*
				std::list<FormeAbstraitePremisse::PtrFormeAbstraitePremisse> premisses;
				premisses.push_back(premisse());
				while(precharge_.estEt()){
					suivant();
					premisses.push_back(premisse());

				}
				return premisses;
			}

			FormeAbstraitePremisse::PtrFormeAbstraitePremisse
			Syntaxique::premisse(){
				// premisse_bool || premisse_symb || premisse_ent
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
	            throw MonException(lexical_, "attendu: un identificateur ou un 'non'");
			}

			FormeAbstraitePremisse::PtrFormeAbstraitePremisse
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
					FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse(new FormePremisseBoolFalse(it->first));
					suivant();
					return premisse;
				}
				else{
					FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse(new FormePremisseBoolTrue(precharge_.lireRepresentation()));
					suivant();
					return premisse;
				}
			}


			FormeAbstraitePremisse::PtrFormeAbstraitePremisse
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
						FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new FormePremisseSymboliqueConstante(symb.lireRepresentation(), compEqualEqual, precharge_.lireRepresentation()));
						suivant();
						return premisse;
					}

					else if(signe.estDifferent()){
						FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new FormePremisseSymboliqueConstante(symb.lireRepresentation(), compDiff, precharge_.lireRepresentation()));
						suivant();
						return premisse;
					}
	                else
	                {
	                    throw "La partie n'a pas été trouvée.";
	                }
				}
				else{
					if(it->second != "symbolique"){
						throw MonException(lexical_, "le fait n'est pas symbolique");
					}
					if(signe.estEgal()){
						FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new FormePremisseSymboliqueConstante(symb.lireRepresentation(), compEqualEqual, it->first));
						suivant();
						return premisse;
					}

					else if(signe.estDifferent()){
						FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new FormePremisseSymboliqueConstante(symb.lireRepresentation(), compDiff, it->first));
						suivant();
						return premisse;
					}
	                else
	                {
	                    throw "La partie n'a pas été trouvée.";
	                }
				}

			}

			FormeAbstraitePremisse::PtrFormeAbstraitePremisse
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
					FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new FormePremisseEntierExpression(ent.lireRepresentation(), compEqualEqual, expressionEntiere()));
					return premisse;
				}
				else if(signe.estSuperieur()){
					suivant();
					FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse(new FormePremisseEntierExpression(ent.lireRepresentation(), compSup, expressionEntiere()));
					return premisse;
				}
				else if(signe.estInferieur()){
					suivant();
					FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new FormePremisseEntierExpression(ent.lireRepresentation(), compLess, expressionEntiere()));
					return premisse;
				}
				else if(signe.estSupEgal()){
					suivant();
					FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new FormePremisseEntierExpression(ent.lireRepresentation(), compSupEqual, expressionEntiere()));
					return premisse;
				}
				else if(signe.estInfEgal()){
					suivant();
					FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new FormePremisseEntierExpression(ent.lireRepresentation(), compLessEqual, expressionEntiere()));
					return premisse;
				}
				else if(signe.estDifferent()){
					suivant();
					FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new FormePremisseEntierExpression(ent.lireRepresentation(), compDiff, expressionEntiere()));
					return premisse;
				}
	            else
	            {
	                throw "L'opérateur n'a pas été trouvé.";
	            }
			}
		}
	}
}
