#ifndef Syntaxique_hpp
#define Syntaxique_hpp

#include "lexical.hpp"
#include "VisiteurForme.hpp"
#include "FormeConclusionBoolTrue.hpp"
#include "FormeConclusionBoolFalse.hpp"
#include "FormeConclusionEntierExpression.hpp"
#include "FormeConclusionEntierFait.hpp"
#include "FormeConclusionSymboliqueConstante.hpp"
#include "FormeConclusionSymboliqueFait.hpp"
#include "FeuilleConstante.hpp"
#include "FeuilleFait.hpp"
#include "OperateurAbstrait.hpp"
#include "OperateurPlus.hpp"
#include "OperateurMoins.hpp"
#include "OperateurMul.hpp"
#include "OperateurDiv.hpp"
#include "RegleSansPremisse.hpp"
#include "RegleAvecPremisse.hpp"
#include <map>
#include <iterator>
#include <list>
#include <iostream>
/**
 * @namespace sysexp
 *
 **/
 namespace sysexp{
 /**
	   * @namespace sysexp::builders
	   *
	  **/
	 namespace builders{
		
		/**
		 * @class Syntaxique syntaxique.hpp
		 * Classe representant un analyseur syntaxique de la grammaire.
		 *
		 */
		class Syntaxique{
			
			public:
				/**
				  * Constructeur de la classe Syntaxique
                  * @param [in] lexical  analyseur lexical.
                  */
				Syntaxique(Lexical & lexical);
				
			public: 
				/**
				 * Accesseur.
				 *
				 * @return l'analyseur lexical de l'analyseur syntaxique.
				*/
				const Lexical lireLexical();

				
				/**
				 * parseur de la grammaire lorraine.
				 *
				*/
				sysexp::modele::RegleAbstraite::PtrRegleAbstraite parser();

			protected:
				/**
				 * passe au jeton suivant.
				 *
				*/
				void suivant();
				
				/**
				 * brique parsant les déclarations.
				 *
				*/
				void declarations();

				/**
				 * brique parsant les déclarations booléennes.
				 *
				*/
				void declarations_bool();

				/**
				 * brique parsant les déclarations symboliques.
				 *
				*/
				void declarations_symb();

				/**
				 * brique parsant les déclarations entieres.
				 *
				*/
				void declarations_ent();

				/**
				 * brique parsant les faits.
				 *
				*/
				void listeFaits(std::string valeur);
				
				/**
				 * brique parsant les regles.
				 *
				*/
				sysexp::modele::RegleAbstraite::PtrRegleAbstraite regles();

				/**
				 * brique parsant une regle.
				 *
				*/
				sysexp::modele::RegleAbstraite::PtrRegleAbstraite regle(int i);

				/**
				 * brique parsant une regle sans premisse.
				 *
				*/
				sysexp::modele::RegleAbstraite::PtrRegleAbstraite regle_sans_premisse(int i);

				/**
				 * brique parsant une conclusion.
				 *
				*/
				sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion();

				/**
				 * brique parsant une conclusion booléenne.
				 *
				*/
				sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion_booleenne();

				/**
				 * brique parsant une conclusion symbolique.
				 *
				*/
				sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion_symbolique();

				/**
				 * brique parsant une conclusion entiere.
				 *
				*/
				sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion_entiere();

				/**
				 * brique parsant une expression entiere.
				 *
				*/
				sysexp::modele::ValeurAbstraite::PtrValeur expressionEntiere();

				/**
				 * brique parsant un terme.
				 *
				*/
				sysexp::modele::ValeurAbstraite::PtrValeur terme();

				/**
				 * brique parsant un facteur.
				 *
				*/
				sysexp::modele::ValeurAbstraite::PtrValeur facteur();

				/**
				 * brique parsant une regle avec premisse.
				 *
				*/
				sysexp::modele::RegleAvecPremisse::PtrRegleAbstraite regle_avec_premisse(int i);

				/**
				 * brique parsant une condition.
				 *
				*/
				std::list<sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse> condition();
				
				/**
				 * brique parsant une premisse.
				 *
				*/
				sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse();

				/**
				 * brique parsant une premisse booléenne.
				 *
				*/
				sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse_booleenne();

				/**
				 * brique parsant une premisse symbolique.
				 *
				*/
				sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse_symbolique();

				/**
				 * brique parsant une premisse entiere.
				 *
				*/
				sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse_entiere();
				
			protected:
				/**
				* Analyseur lexical.
				*/
				Lexical & lexical_;
				/**
				* Dernier jeton precharge.
				*/
				Jeton precharge_;

				/**
				 * map de faits (temporaire).
				*/
				std::map <std::string, std::string> faits_;


		};
	}
}
#endif
