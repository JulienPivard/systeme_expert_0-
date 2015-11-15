/**
 * @file fabriqueJeton.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
 *
 * Header pour le fichier fabriqueJeton.cpp.
 * Définit la classe FabriqueJeton.
 * */

#ifndef FabriqueJeton_hpp
#define FabriqueJeton_hpp

#include "jeton.hpp"

 namespace sysexp{
 
	 namespace builders{

	 	namespace lorraine{
			/**
			  * @brief Représente une fabrique de jetons de la grammaire lorraine.
			  * Classe representant une fabrique de jetons de la grammaire.
	          */
			class FabriqueJeton{
				public:
					/**
					  * Constructeur de la classe FabriqueJeton
	                  */
					FabriqueJeton();
					
					/**
					  * Retourne le jeton associé à la parenthèse ouvrante.
	                  *
	                  * @return le jeton associé à la parenthèse ouvrante.
	                  */
					static const Jeton parentheseOuvrante();
					
					/**
					  * Retourne le jeton associé à la parenthèse fermante.
	                  *
	                  * @return le jeton associé à la parenthèse fermante.
	                  */
					static const Jeton parentheseFermante();
					
					/**
					  * Retourne le jeton associé au signe inférieur.
	                  *
	                  * @return le jeton associé au signe inférieur.
	                  */
					static const Jeton inferieur();
					
					/**
					  * Retourne le jeton associé au signe supérieur.
	                  *
	                  * @return le jeton associé au signe supérieur.
	                  */
					static const Jeton superieur();
					
					/**
					  * Retourne le jeton associé à l'opérateur plus.
	                  *
	                  * @return le jeton associé à l'opérateur plus.
	                  */
					static const Jeton operateurPlus();
					
					/**
					  * Retourne le jeton associé à l'opérateur moins.
	                  *
	                  * @return le jeton associé à l'opérateur moins.
	                  */
					static const Jeton operateurMoins();
					
					/**
					  * Retourne le jeton associé à l'opérateur multiplié.
	                  *
	                  * @return le jeton associé à l'opérateur multiplié.
	                  */
					static const Jeton operateurMul();
					
					/**
					  * Retourne le jeton associé à l'opérateur divisé.
	                  *
	                  * @return le jeton associé à l'opérateur divisé.
	                  */
					static const Jeton operateurDiv();
					
					/**
					  * Retourne le jeton associé au signe égal.
	                  *
	                  * @return le jeton associé au signe égal.
	                  */
					static const Jeton egal();
					
					/**
					  * Retourne le jeton associé au point virgule.
	                  *
	                  * @return le jeton associé au point virgule.
	                  */
					static const Jeton finExpression();
					
					/**
					  * Retourne le jeton associé au si.
	                  *
	                  * @return le jeton associé au si.
	                  */
					static const Jeton si();
					
					/**
					  * Retourne le jeton associé au non.
	                  *
	                  * @return le jeton associé au non.
	                  */
					static const Jeton non();
					
					/**
					  * Retourne le jeton associé au et.
	                  *
	                  * @return le jeton associé au et.
	                  */
					static const Jeton et();
					
					/**
					  * Retourne le jeton associé au alors.
	                  *
	                  * @return le jeton associé au alors.
	                  */
					static const Jeton alors();
					
					/**
					  * Retourne le jeton associé à la virgule.
	                  *
	                  * @return le jeton associé à la virgule.
	                  */
					static const Jeton separateur();
					
					/**
					  * Retourne le jeton associé à la fin du fichier.
	                  *
	                  * @return le jeton associé à la fin du fichier.
	                  */
					static const Jeton finFichier();
					
					/**
					  * Retourne le jeton associé à un supérieur ou égal.
	                  *
	                  * @return le jeton associé à un supérieur ou égal.
	                  */
					static const Jeton supEgal();

					/**
					  * Retourne le jeton associé à un inférieur ou égal.
	                  *
	                  * @return le jeton associé à un inférieur ou égal.
	                  */
					static const Jeton infEgal();

					/**
					  * Retourne le jeton associé à un différent.
	                  *
	                  * @return le jeton associé à un différent.
	                  */
					static const Jeton different();

					/**
					  * Retourne le jeton associé à faits_booleens.
	                  *
	                  * @return le jeton associé à faits_booleens.
	                  */
					static const Jeton faitBool();

					/**
					  * Retourne le jeton associé à faits_symboliques.
	                  *
	                  * @return le jeton associé à faits_symboliques.
	                  */
					static const Jeton faitSymb();

					/**
					  * Retourne le jeton associé a faits_entiers.
	                  *
	                  * @return le jeton associé a faits_entiers.
	                  */
					static const Jeton faitEnt();

					/**
					  * Retourne le jeton associé à un entier.
	                  *
	                  * @return le jeton associé à un entier.
	                  */
					static const Jeton entier(const std::string & representation);
					
					/**
					  * Retourne le jeton associé à un identificateur.
	                  *
	                  * @return le jeton associé à un identificateur.
	                  */
					static const Jeton identificateur(const std::string & representation);
					
					/**
					  * Retourne le jeton associé à un inconnu.
	                  *
	                  * @return le jeton associé à un inconnu.
	                  */
					static const Jeton inconnu(const std::string & representation);
					
				protected:
				
					/**
					 * jeton parenthèse ouvrante.
					 */
					static const Jeton parentheseOuvrante_; 
					
					/**
					 * jeton parenthèse fermante.
					 */
					static const Jeton parentheseFermante_; 
					
					/**
					 * jeton supérieur.
					 */
					static const Jeton superieur_;
					
					/**
					 * jeton inférieur.
					 */
					static const Jeton inferieur_; 
					
					/**
					 * jeton opérateur plus.
					 */
					static const Jeton operateurPlus_; 
					
					/**
					 * jeton opérateur moins.
					 */
					static const Jeton operateurMoins_;
					
					/**
					 * jeton opérateur multiplie.
					 */
					static const Jeton operateurMul_; 
					
					/**
					 * jeton opérateur divise.
					 */
					static const Jeton operateurDiv_;
					
					/**
					 * jeton égal.
					 */
					static const Jeton egal_;
					
					/**
					 * jeton fin d'expression.
					 */
					static const Jeton finExpression_;
					
					/**
					 * jeton si.
					 */
					static const Jeton si_;
					
					/**
					 * jeton non.
					 */
					static const Jeton non_;
					
					/**
					 * jeton et.
					 */
					static const Jeton et_;
					/**
					 * jeton alors.
					 */
					static const Jeton alors_;
					
					/**
					 * jeton séparateur.
					 */
					static const Jeton separateur_;
					
					/**
					 * jeton fin du fichier.
					 */
					static const Jeton finFichier_;

					/**
					 * jeton supérieur ou égal.
					 */
					static const Jeton supEgal_;

					/**
					 * jeton inférieur ou égal.
					 */
					static const Jeton infEgal_;

					/**
					 * jeton différent.
					 */
					static const Jeton different_;
					
					/**
					 * jeton fait_booleens.
					 */
					static const Jeton faitBool_;

					/**
					 * jeton fait_symboliques.
					 */
					static const Jeton faitSymb_;

					/**
					 * jeton fait_entiers.
					 */
					static const Jeton faitEnt_;
			};
		}
	 }
 }
#endif
