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
#include <map>
#include <iterator>
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
				void parser();

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
				void regles();

				/**
				 * brique parsant une regle.
				 *
				*/
				void regle();

				/**
				 * brique parsant une regle sans premisse.
				 *
				*/
				void regle_sans_premisse();

				/**
				 * brique parsant une conclusion.
				 *
				*/
				void conclusion();

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
				void conclusion_entiere();

				/**
				 * brique parsant une expression entiere.
				 *
				*/
				void expressionEntiere();

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
				void regle_avec_premisse();

				/**
				 * brique parsant une condition.
				 *
				*/
				void condition();
				
				/**
				 * brique parsant une premisse.
				 *
				*/
				void premisse();

				/**
				 * brique parsant une premisse booléenne.
				 *
				*/
				void premisse_booleenne();

				/**
				 * brique parsant une premisse symbolique.
				 *
				*/
				void premisse_symbolique();

				/**
				 * brique parsant une premisse entiere.
				 *
				*/
				void premisse_entiere();
				
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
