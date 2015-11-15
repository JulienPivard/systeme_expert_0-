/**
 * @file syntaxique.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
 *
 * Header pour le fichier syntaxique.cpp.
 * Définit la classe Syntaxique.
 * */

#ifndef Syntaxique_hpp
#define Syntaxique_hpp

#include <map>
#include <iterator>
#include <list>
#include <iostream>
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


 namespace sysexp{
 	
	 namespace builders{

	 	namespace lorraine{
		
			/**
			 * @brief Représente un analyseur syntaxique et sémantique de la grammaire lorraine.
			 * Classe representant un analyseur syntaxique de la grammaire.
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
					 * @return l'analyseur lexical de l'analyseur syntaxique.
					*/
					const Lexical lireLexical();

					
					/**
					 * Parseur de la grammaire lorraine.
					 * @return une base de règle de la grammaire lorraine.
					*/
					sysexp::modele::RegleAbstraite::PtrRegleAbstraite parser();

				protected:
					/**
					 * Passe au jeton suivant.
					*/
					void suivant();
					
					/**
					 * Brique parsant les déclarations.
					*/
					void declarations();

					/**
					 * Brique parsant les déclarations booléennes.
					*/
					void declarations_bool();

					/**
					 * Brique parsant les déclarations symboliques.
					*/
					void declarations_symb();

					/**
					 * Brique parsant les déclarations entieres.
					*/
					void declarations_ent();

					/**
					 * Brique parsant les faits.
					*/
					void listeFaits(std::string valeur);
					
					/**
					 * Brique parsant les règles.
					 * @return une base de règle de la grammaire lorraine.
					*/
					sysexp::modele::RegleAbstraite::PtrRegleAbstraite regles();

					/**
					 * Brique parsant une règle.
					 * @return une règle.
					*/
					sysexp::modele::RegleAbstraite::PtrRegleAbstraite regle(int i);

					/**
					 * Brique parsant une règle sans prémisse.
					 * @return une règle sans prémisse.
					*/
					sysexp::modele::RegleAbstraite::PtrRegleAbstraite regle_sans_premisse(int i);

					/**
					 * Brique parsant une conclusion.
					 * @return une conclusion.
					*/
					sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion();

					/**
					 * Brique parsant une conclusion booléenne.
					 * @return une conclusion booléenne.
					*/
					sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion_booleenne();

					/**
					 * Brique parsant une conclusion symbolique.
					 * @return une conclusion symbolique.
					*/
					sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion_symbolique();

					/**
					 * Brique parsant une conclusion entiere.
					 * @return une conclusion entiere.
					*/
					sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion_entiere();

					/**
					 * Brique parsant une expression entiere.
					 * @return une expression entiere.
					*/
					sysexp::modele::ValeurAbstraite::PtrValeur expressionEntiere();

					/**
					 * Brique parsant un terme.
					 * @return un terme.
					*/
					sysexp::modele::ValeurAbstraite::PtrValeur terme();

					/**
					 * Brique parsant un facteur.
					 * @return un facteur.
					*/
					sysexp::modele::ValeurAbstraite::PtrValeur facteur();

					/**
					 * Brique parsant une règle avec prémisse.
					 * @return une règle avec prémisse.
					*/
					sysexp::modele::RegleAvecPremisse::PtrRegleAbstraite regle_avec_premisse(int i);

					/**
					 * Brique parsant une condition.
					 * @return une condition.
					*/
					std::list<sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse> condition();
					
					/**
					 * Brique parsant une prémisse.
					 * @return une prémisse.
					*/
					sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse();

					/**
					 * Brique parsant une prémisse booléenne.
					 * @return une prémisse booléenne.
					*/
					sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse_booleenne();

					/**
					 * Brique parsant une prémisse symbolique.
					 * @return une prémisse symbolique.
					*/
					sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse_symbolique();

					/**
					 * Brique parsant une prémisse entiere.
					 * @return une prémisse entiere.
					*/
					sysexp::modele::FormeAbstraitePremisse::PtrFormeAbstraitePremisse premisse_entiere();
					
				protected:
					/**
					* Analyseur lexical.
					*/
					Lexical & lexical_;
					
					/**
					* Dernier jeton prechargé.
					*/
					Jeton precharge_;

					/**
					 * map de faits.
					*/
					std::map <std::string, std::string> faits_;
			};
		}
	}
}
#endif
