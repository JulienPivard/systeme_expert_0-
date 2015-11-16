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
	          */
			class FabriqueJeton{
				public:
					/**
					  * Constructeur de la classe FabriqueJeton
	                  */
					FabriqueJeton();

					/**
	                  * @return le jeton associé à la parenthèse ouvrante.
	                  */
					static const Jeton parentheseOuvrante();

					/**
	                  * @return le jeton associé à la parenthèse fermante.
	                  */
					static const Jeton parentheseFermante();

					/**
	                  * @return le jeton associé au signe inférieur.
	                  */
					static const Jeton inferieur();

					/**
	                  * @return le jeton associé au signe supérieur.
	                  */
					static const Jeton superieur();

					/**
	                  * @return le jeton associé à l'opérateur plus.
	                  */
					static const Jeton operateurPlus();

					/**
	                  * @return le jeton associé à l'opérateur moins.
	                  */
					static const Jeton operateurMoins();

					/**
	                  * @return le jeton associé à l'opérateur multiplié.
	                  */
					static const Jeton operateurMul();

					/**
	                  * @return le jeton associé à l'opérateur divisé.
	                  */
					static const Jeton operateurDiv();

					/**
	                  * @return le jeton associé au signe égal.
	                  */
					static const Jeton egal();

					/**
	                  * @return le jeton associé au point virgule.
	                  */
					static const Jeton finExpression();

					/**
	                  * @return le jeton associé au si.
	                  */
					static const Jeton si();

					/**
	                  * @return le jeton associé au non.
	                  */
					static const Jeton non();

					/**
	                  * @return le jeton associé au et.
	                  */
					static const Jeton et();

					/**
	                  * @return le jeton associé au alors.
	                  */
					static const Jeton alors();

					/**
	                  * @return le jeton associé à la virgule.
	                  */
					static const Jeton separateur();

					/**
	                  * @return le jeton associé à la fin du fichier.
	                  */
					static const Jeton finFichier();

					/**
	                  * @return le jeton associé à un supérieur ou égal.
	                  */
					static const Jeton supEgal();

					/**
	                  * @return le jeton associé à un inférieur ou égal.
	                  */
					static const Jeton infEgal();

					/**
	                  * @return le jeton associé à un différent.
	                  */
					static const Jeton different();

					/**
	                  * @return le jeton associé à faits_booleens.
	                  */
					static const Jeton faitBool();

					/**
	                  * @return le jeton associé à faits_symboliques.
	                  */
					static const Jeton faitSymb();

					/**
	                  * @return le jeton associé a faits_entiers.
	                  */
					static const Jeton faitEnt();

					/**
	                  * @return le jeton associé à un entier.
	                  */
					static const Jeton entier(const std::string & representation);

					/**
	                  * @return le jeton associé à un identificateur.
	                  */
					static const Jeton identificateur(const std::string & representation);

					/**
	                  * @return le jeton associé à un inconnu.
	                  */
					static const Jeton inconnu(const std::string & representation);

                public:

                    FabriqueJeton( const FabriqueJeton & autre ) = delete;

                    FabriqueJeton & operator=( const FabriqueJeton & autre ) = delete;

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
