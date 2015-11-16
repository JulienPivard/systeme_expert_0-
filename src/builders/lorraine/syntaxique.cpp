#include "syntaxique.hpp"
#include "monException.hpp"

// on utilise using namespace ici 
// pour pas que la création des objets prenne 3 kilometres de long 
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
				// il y a trois types de déclarations:
				declarations_bool(); // les déclarations booléennes,
				declarations_symb(); // les déclarations symboliques,
				declarations_ent(); // et les déclarations entieres.
				// dans la grammaire lorraine ces déclarations sont dans cet ordre,
				// si les déclarations ne sont pas dans cet ordre il y aura une exception.
			}

			void
			Syntaxique::declarations_bool(){
				// on regarde si on fait des déclarations booléennes.
				if(!precharge_.estFaitBool())
					throw MonException(lexical_, "attendu: 'faits_booleens'");
				suivant();
				// on construit la map contenant un fait et son type.
				listeFaits("booleen");
			}


			void
		 	Syntaxique::declarations_symb(){
		 		// on regarde si on fait des déclarations symboliques.
		 		if(!precharge_.estFaitSymb())
					throw MonException(lexical_,"attendu: 'faits_symboliques'");
				suivant();
				// on construit la map contenant un fait et son type.
				listeFaits("symbolique");
			}

			void
			Syntaxique::declarations_ent(){
				// on regarde si on fait des déclarations entières
				if(!precharge_.estFaitEnt())
					throw MonException(lexical_, "attendu: 'faits_entiers'");
				suivant();
				// on construit la map contenant un fait et son type.
				listeFaits("entier");
			}

			void
			Syntaxique::listeFaits(std::string valeur){
				// on regarde si la structure des déclarations est bien respectée.
				if (!precharge_.estEgal()) // apres le type de fait déclaré, on doit trouver un égal.
					throw MonException(lexical_, "attendu: '='");
				suivant();

				while(!precharge_.estFinExpression()){ // tant qu'on ne rencontre pas un point virgule...
					if(!precharge_.estIdentificateur()) // on regarde si on a une chaine de caractere...
						throw MonException(lexical_, "attendu: un identificateur ou un '_'");
					faits_[precharge_.lireRepresentation()] = valeur;// on l'ajoute a une map qui associe un fait a sa valeur ( bool, symb, entier)
					suivant();

					if(precharge_.estFinExpression()){ // apres chaque fait trouvé, on regarde si on est a la fin de la déclaration. 
						suivant();
						break;
					}
					if (!precharge_.estSeparateur()) // si on est pas a la fin de la déclatation, les faits sont séparés par une virgule, on regarde donc si elle est bien présente.
						throw MonException(lexical_,"attendu: ','");
					suivant();
				}
			}

			RegleAbstraite::PtrRegleAbstraite
			Syntaxique::regles(){
				// apres avoir parsé les déclarations, il nous reste que des regles.
				// pour créer la base de regle on a besoin d'une regle pour la chainer à son successeur.
				RegleAbstraite::PtrRegleAbstraite regleSuiv;
				int i = 0;
				while(!precharge_.estFinFichier()){ 
					RegleAbstraite::PtrRegleAbstraite reglePrec = regle(i); // on crée une règle
					reglePrec->ajouterSuccesseur(regleSuiv); // puis on la chaine à son successeur
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
					return regle_avec_premisse(i); // une regle avec prémisse commence toujours par "si",
				}
				else{
					return regle_sans_premisse(i);// si ce n'est pas le cas c'est donc une regle sans prémisse.
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
				if(precharge_.estIdentificateur()){ // une conclusion est une chaine de caractere; un identificateur.
					std::map<std::string, std::string>::iterator it = faits_.find(precharge_.lireRepresentation());// on regarde si l'identificateur rencontré est dans la map de faits.
					if(it == faits_.end()){
						throw MonException(lexical_, "le fait n'a pas été declare");
					}
					else if(it->second == "booleen"){ // si il est booléen c'est une conclusion booléenne,
						return conclusion_booleenne();
					}
					else if(it->second == "symbolique"){ // si il est symbolique c'est une conclusion symbolique,
						return conclusion_symbolique();
					}
					else if(it->second == "entier"){ // si il est entier c'est une conclusion entiere.
						return conclusion_entiere();
					}
				}
				else if(precharge_.estNon()){
					return conclusion_booleenne(); // si l'identificateur rencontré est un non, c'est une conclusion booléenne.
				}
				throw MonException(lexical_, "attendu: un identificateur ou un 'non'");
			}

			FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion
			Syntaxique::conclusion_booleenne(){
				// une conclusion booléenne est constituée soit d'un fait_booléen ou de "non" fait_booléen.
				if(precharge_.estNon()){// si la conclusion booléenne commence par un non, on ne sais pas si le jeton suivant est un fait booléen.
					suivant();
					if(!precharge_.estIdentificateur()){// on regarde donc si c'est une chaine de caractere... 
						throw MonException(lexical_, "attendu: un fait booléen");
					}
					std::map<std::string, std::string>::iterator it = faits_.find(precharge_.lireRepresentation());// ...si le fait existe...
					if(it == faits_.end()){
						throw MonException(lexical_, "le fait n'a pas été declare");
					}
					else if(it->second != "booleen"){ // ...et qu'il est booléen.
						throw MonException(lexical_, "le fait n'est pas booléen");
					}
					// si tout se passe bien, on crée une conclusion booléenne false. 
					FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion(new FormeConclusionBoolFalse(it->first)); 
					suivant();
					return conclusion;
				}
				else{
					// si la conclusion booléenne ne commence pas par un non, on sait qu'on a un fait booléen, on construit donc une conclusion booléenne true.
					FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion(new FormeConclusionBoolTrue(precharge_.lireRepresentation())); 
					suivant();
					return conclusion;
				}
			}

			FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion
			Syntaxique::conclusion_symbolique(){
				// pour construire une conclusion symbolique on a besoin de garder le jeton qui contient le fait.
				Jeton symb = precharge_ ;
				suivant();
				if(!precharge_.estEgal()){// on regarde si on a un égal car la structure d'une conclusion symbolique est : fait_symbolique = (fait_symbolique | constante_symbolique) 
					throw MonException(lexical_, "attendu '='");
				}
				suivant();

				if(!precharge_.estIdentificateur()){ // apres le égal on et censé trouver un identificateur
						throw MonException(lexical_, "attendu : identificateur");
				}

				std::map<std::string, std::string>::iterator it = faits_.find(precharge_.lireRepresentation()); // on regarde si il est dans la liste de faits...
				if(it == faits_.end()){// si il n'y est pas c'est donc une constante symbolique
					// on crée dans une conclusion symbolique constante.
					FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion(new FormeConclusionSymboliqueConstante(symb.lireRepresentation(), precharge_.lireRepresentation()));
					suivant();
					return conclusion;
				}
				else{
					if(it->second != "symbolique"){
						throw MonException(lexical_, "le fait n'est pas symbolique");
					}
					// si il est symbolique, on crée une conclusion symbolique fait
					FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion(new FormeConclusionSymboliqueFait(symb.lireRepresentation(), it->first));
					suivant();
					return conclusion;
				}
			}

			FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion
			Syntaxique::conclusion_entiere(){
				// pour construire une conclusion entiere on a besoin du fait entier que l'on a rencontré.
				Jeton ent = precharge_;
				suivant();
				if(!precharge_.estEgal()){ // on regarde si on a un égal car la structure d'une conclusion entiere est : fait_entier = expressionEntiere
					throw MonException(lexical_, "attendu: '='");
				}
				suivant();
				// si tout va bien, on construit la conclusion entiere
				FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion(new FormeConclusionEntierExpression(ent.lireRepresentation(), expressionEntiere()));
				return conclusion;
			}

			ValeurAbstraite::PtrValeur
			Syntaxique::expressionEntiere(){
				// la structure d'une valeur entiere est (+|-) terme {(+|-) terme}
				ValeurAbstraite::PtrValeur facteur_g;
				if(precharge_.estOperateurPlus()){ // si on rencontre un + au début d'une expression entiere ce n'est pas une faute, il est juste ignoré
					suivant();
					facteur_g = terme(); // la partie gauche de l'opération prend la valeur du terme rencontré.
				}
				else if(precharge_.estOperateurMoins()){ // si on rencontre un opérateur moins
					suivant();
					FeuilleConstante::PtrFeuilleConstante f(new FeuilleConstante(0)); // on va faire 0 - (la valeur qui sera rencontrée)
					facteur_g = terme();
					OperateurMoins::PtrOperateurMoins opm(new OperateurMoins(f, facteur_g));
	                facteur_g = opm;// la partie gauche de l'operation prend donc la valeur de cette soustraction, on a bien -x. 
				}
				else{
					facteur_g = terme(); //sinon tout se passe bien et on a la valeur du terme directement
				}
				while(precharge_.estOperateurPlus() || precharge_.estOperateurMoins()){ // ensuite tant qu'on rencontre encore des opérateur plus ou moins
					if(precharge_.estOperateurPlus()){ // pour le plus
						suivant();
						ValeurAbstraite::PtrValeur facteur_d = terme(); // on récupére la valeur de la partie droite de l'opération...
						OperateurPlus::PtrOperateurPlus oppl(new OperateurPlus(facteur_g, facteur_d)); //... on l'additionne a la partie gauche ...
						facteur_g = oppl;// ...et la somme devient la partie gauche de l'opération.
					}
					if(precharge_.estOperateurMoins()){ // pour le moins
						suivant();
						ValeurAbstraite::PtrValeur facteur_d = terme();// on récupére la valeur de la partie droite de l'opération...
						OperateurMoins::PtrOperateurMoins opm(new OperateurMoins(facteur_g, facteur_d)); //... on la soustrait a la partie gauche ...
						facteur_g = opm; // ... et la difference devient la partie gauche de l'opération.
					}
				}
				return facteur_g;
			}

			ValeurAbstraite::PtrValeur
			Syntaxique::terme(){
				// la structure d'un terme est : facteur {x facteur}
				ValeurAbstraite::PtrValeur facteur_g = facteur(); // on récupére la valeur du facteur gauche
				while(precharge_.estOperateurMul() || precharge_.estOperateurDiv()){ // tant qu'on rencontre les opérateurs mul et div
					if(precharge_.estOperateurMul()){ // pour le mul
						suivant();
						ValeurAbstraite::PtrValeur facteur_d = facteur(); // on récupére la valeur du facteur droite
						OperateurMul::PtrOperateurMul opmul(new OperateurMul(facteur_g, facteur_d)); // on le multiplie au facteur gauche
						facteur_g = opmul; // le produit obtenu devient le facteur gauche
					}
					if(precharge_.estOperateurDiv()){ // pour le div
						suivant();
						ValeurAbstraite::PtrValeur facteur_d = facteur(); // on récupére la valeur du facteur droite
						OperateurDiv::PtrOperateurDiv opd(new OperateurDiv(facteur_g, facteur_d)); // on la divise au facteur gauche
						facteur_g = opd; // le résultat de la division devient le facteur gauche.
					}
				}
				return facteur_g;
			}

			ValeurAbstraite::PtrValeur
			Syntaxique::facteur(){
				// un facteur est composé d'une constante entiere, d'un fait entier ou d'une expression entiere entre parenthèse.
				std::map<std::string, std::string>::iterator it = faits_.find(precharge_.lireRepresentation()); // on regarde si le jeton courant est un fait entier.
				if(it == faits_.end()){
					if(precharge_.estEntier()){// si c'en est pas un et que c'est un entier, on construit une feuille de valeur constante.
						FeuilleConstante::PtrFeuilleConstante val(new FeuilleConstante(std::stoi(precharge_.lireRepresentation())));
						suivant();
						return val;
					}
					else if(precharge_.estParentheseOuvrante()){// si on rencontre une parenthese ouvrante, c'est une expression entiere
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
					if(it->second != "entier"){// si le fait est entier
						throw MonException(lexical_, "le fait n'est pas entier");
					}
					FeuilleFait::PtrFeuilleFait val(new FeuilleFait(it->first)); // on créé une feuille fait
					suivant();
					return val;
				}
			}

			RegleAvecPremisse::PtrRegleAbstraite
			Syntaxique::regle_avec_premisse(int i){
				// une regle avec prémisse est constituée d'un si suivi de conditions d'un alors et d'une conclusion.
				suivant();// on a rencontré un si on passe au jeton suivant
				std::list<FormeAbstraitePremisse::PtrFormeAbstraitePremisse>  premisses = condition(); // on constuit les conditions
				if(!precharge_.estAlors()){
					throw MonException(lexical_, "attendu: 'alors'");
				}
				suivant();
	            // On chope le premier element de la liste des conditions pour créer une regle avec une conclusion.
				RegleAvecPremisse::PtrRegleAvecPremisse regle( new RegleAvecPremisse(i, premisses.front(), conclusion() ));
				// puis on ajoute les prémisses si il en reste encore.
				for(std::list<FormeAbstraitePremisse::PtrFormeAbstraitePremisse>::iterator it = premisses.begin()++; it != premisses.end(); ++it){
	    			regle->ajouterPremisse(*it);
	    		}
				return regle;
			}

			std::list<FormeAbstraitePremisse::PtrFormeAbstraitePremisse>
			Syntaxique::condition(){
				//une condition est constituée d'une ou plusieurs prémisses séparées par le mot "et"
				std::list<FormeAbstraitePremisse::PtrFormeAbstraitePremisse> premisses;
				premisses.push_back(premisse());// on a forcément une prémisse, on l'ajoute donc à la liste
				while(precharge_.estEt()){ // tant qu'on rencontre des "et"
					suivant();
					premisses.push_back(premisse());// on ajoute les prémisses à la liste de prémisses

				}
				return premisses;
			}

			FormeAbstraitePremisse::PtrFormeAbstraitePremisse
			Syntaxique::premisse(){
				// une prémisse est soit booléenne, symbolique ou entiere.
				if(precharge_.estIdentificateur()){ // on regarde si on a un identificateur
					std::map<std::string, std::string>::iterator it = faits_.find(precharge_.lireRepresentation()); // on regarde si l'identificateur est dans la liste de faits
					if(it == faits_.end()){
						throw MonException(lexical_, "le fait n'a pas été declare");
					}
					else if(it->second == "booleen"){ // si il est booléen c'est une prémisse booléenne
						return premisse_booleenne();
					}
					else if(it->second == "symbolique"){ // si il est symbolique c'est une prémisse symbolique
						return premisse_symbolique();
					}
					else if(it->second == "entier"){ // si il est entier, c'est une prémisse entiere
						return premisse_entiere();
					}
				}
				else if(precharge_.estNon()){
					return premisse_booleenne(); // si c'est un non, c'est une prémisse booléenne
				}
	            throw MonException(lexical_, "attendu: un identificateur ou un 'non'");
			}

			FormeAbstraitePremisse::PtrFormeAbstraitePremisse
			Syntaxique::premisse_booleenne(){
				if(precharge_.estNon()){ // si on a un non
					suivant();
					if(!precharge_.estIdentificateur()){// on regarde si on a un identificateur
						throw MonException(lexical_, "attendu: un fait booléen");
					}
					std::map<std::string, std::string>::iterator it = faits_.find(precharge_.lireRepresentation());// on regarde si il est dans la liste de faits
					if(it == faits_.end()){
						throw MonException(lexical_, "le fait n'a pas été declare");
					}
					else if(it->second != "booleen"){
						throw MonException(lexical_, "le fait n'est pas booléen");
					}
					// si le fait existe et qu'il est booléen on crée la prémisse booléenne false
					FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse(new FormePremisseBoolFalse(it->first));
					suivant();
					return premisse;
				}
				else{
					// pour la prémisse booléenne true, on a déja regardé si le fait est dans la liste de fait et qu'il est boooléen
					// on crée donc une premisse booléenne true.
					FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse(new FormePremisseBoolTrue(precharge_.lireRepresentation()));
					suivant();
					return premisse;
				}
			}


			FormeAbstraitePremisse::PtrFormeAbstraitePremisse
			Syntaxique::premisse_symbolique(){
				// pour créer une prémisse symbolique on a besoin du jeton contenent le fait.
				Jeton symb = precharge_;
				suivant();
				// la structure d'une prémisse symbolique est : fait_symbolique (= | /=)(fait_symbolique | constante_symbolique)
				if(!precharge_.estEgal() && !precharge_.estDifferent()){ // on regarde donc si on a le signe egal ou différent
					throw MonException(lexical_, "attendu: '=' ou '/='");
				}
				Jeton signe = precharge_;// on garde le signe rencontré pour créer la premisse
				suivant();

				if(!precharge_.estIdentificateur()){ // on regarde ensuite si on a un identificateur
						throw MonException(lexical_, "attendu : identificateur");
				}

				std::map<std::string, std::string>::iterator it = faits_.find(precharge_.lireRepresentation());// on regarde si cet identificateur est dans la liste de faits
				if(it == faits_.end()){
					if(signe.estEgal()){ // si il n'est pas dans la liste et que le signe rencontré précedemment est un égal
						// on crée une prémisse symbolique constante
						FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new FormePremisseSymboliqueConstante(symb.lireRepresentation(), compEqualEqual, precharge_.lireRepresentation()));
						suivant();
						return premisse;
					}

					else if(signe.estDifferent()){ //si il n'est pas dans la liste et que le signe rencontré précedemment est un différent
						// on crée une prémisse symbolique constante
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
					if(signe.estEgal()){// si le fait est dans la liste de faits et que le signe rencontré précedemment est un égal
						// on crée une premisse symbolique fait
						FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new FormePremisseSymboliqueFait(symb.lireRepresentation(), compEqualEqual, it->first));
						suivant();
						return premisse;
					}

					else if(signe.estDifferent()){ // si le fait est dans la liste de faits et que le signe rencontré précedemment est un différent
						// on crée une premisse symbolique fait
						FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new FormePremisseSymboliqueFait(symb.lireRepresentation(), compDiff, it->first));
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
				// pour créer une prémisse entiere, il faut garder le jeton contenent le fait entier
				Jeton ent = precharge_;
				suivant();
				// on regarde si on a un signe de comparaison.
				if(!precharge_.estEgal() && !precharge_.estSuperieur() && !precharge_.estInferieur() &&
					!precharge_.estSupEgal() && !precharge_.estInfEgal() && !precharge_.estDifferent()){
					throw MonException(lexical_, "attendu : '=' ou '/=' ou '<' ou '>' ou '<=' ou '>='");
				}
				Jeton signe = precharge_; // on enregistre le signe rencontré
				if(signe.estEgal()){ // si le signe rencontré est un egal
					suivant();
					FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new FormePremisseEntierExpression(ent.lireRepresentation(), compEqualEqual, expressionEntiere()));
					return premisse;
				}
				else if(signe.estSuperieur()){// si le signe rencontré est un superieur
					// on crée une prémisse entiere
					suivant();
					FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse(new FormePremisseEntierExpression(ent.lireRepresentation(), compSup, expressionEntiere()));
					return premisse;
				}
				else if(signe.estInferieur()){// si le signe rencontré est un inferieur
					// on crée une prémisse entiere
					suivant();
					FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new FormePremisseEntierExpression(ent.lireRepresentation(), compLess, expressionEntiere()));
					return premisse;
				}
				else if(signe.estSupEgal()){// si le signe rencontré est un superieur ou egal
					// on crée une prémisse entiere
					suivant();
					FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new FormePremisseEntierExpression(ent.lireRepresentation(), compSupEqual, expressionEntiere()));
					return premisse;
				}
				else if(signe.estInfEgal()){// si le signe rencontré est un inferieur ou egal
					// on crée une prémisse entiere
					suivant();
					FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse( new FormePremisseEntierExpression(ent.lireRepresentation(), compLessEqual, expressionEntiere()));
					return premisse;
				}
				else if(signe.estDifferent()){// si le signe rencontré est un différent
					// on crée une prémisse entiere
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
