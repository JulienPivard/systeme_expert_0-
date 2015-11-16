/**
 * @file jeton.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
 *
 * Header pour le fichier jeton.cpp.
 * Définit la classe Jeton.
 * */

#ifndef Jeton_hpp
#define Jeton_hpp

#include <string>

namespace sysexp{

	namespace builders{

		namespace lorraine{

			/**
			 * @brief Représente un type de jeton.
			 */
			enum class TypeJeton{
				parentheseOuvrante, parentheseFermante, superieur, inferieur,
				operateurPlus, operateurMoins, operateurMul, operateurDiv,
				egal, finExpression, identificateur, entier,
				si, non, et, alors, separateur, inconnu, finFichier, supEgal, infEgal, different,
				faitBool, faitSymb, faitEnt
			};

			/**
			 * @brief Représente un jeton de la grammaire Lorraine.
			 */
			class Jeton{

				public:
					/**
					 * Accesseur.
					 *
					 * @return la valeur de @ref type_.
					 */
					const TypeJeton & lireType() const;

					/**
					 * Accesseur.
					 *
					 * @return la valeur de @ref representation_.
					 */
					const std::string& lireRepresentation() const;

					/**
					 * Indique si le jeton est une parenthèse ouvrante.
					 * @return true si le jeton est une parenthèse ouvrante, false sinon.
					 */
					bool estParentheseOuvrante() const;

					/**
					 * Indique si le jeton est une parenthèse fermante.
					 * @return true si le jeton est une parenthèse fermante, false sinon.
					 */
					bool estParentheseFermante() const;

					/**
					 * Indique si le jeton est supérieur.
					 * @return true si le jeton est un supérieur, false sinon.
					 */
					bool estSuperieur() const;

					/**
					 * Indique si le jeton est inferieur.
					 * @return true si le jeton est un inférieur, false sinon.
					 */
					bool estInferieur() const;

					/**
					 * Indique si le jeton est un plus.
					 * @return true si le jeton est un plus, false sinon.
					 */
					bool estOperateurPlus() const;

					/**
					 * Indique si le jeton est un moins.
					 * @return true si le jeton est un moins, false sinon.
					 */
					bool estOperateurMoins() const;

					/**
					 * Indique si le jeton est un fois.
					 * @return true si le jeton est un fois, false sinon.
					 */
					bool estOperateurMul() const;

					/**
					 * Indique si le jeton est un div.
					 * @return true si le jeton est un div, false sinon.
					 */
					bool estOperateurDiv() const;

					/**
					 * Indique si le jeton est un égal
					 * @return true si le jeton est un égal, false sinon.
					 */
					bool estEgal() const;

					/**
					 * Indique si le jeton est un point virgule.
					 * @return true si le jeton est un point virgule, false sinon.
					 */
					bool estFinExpression() const;

					/**
					 * Indique si le jeton est un identificateur.
					 * @return true si le jeton est un identificateur, false sinon.
					 */
					bool estIdentificateur() const;

					/**
					 * Indique si le jeton est un si .
					 * @return true si le jeton est un si, false sinon.
					 */
					bool estSi() const;

					/**
					 * Indique si le jeton est un non.
					 * @return true si le jeton est un non, false sinon.
					 */
					bool estNon() const;


					/**
					 * Indique si le jeton est un et.
					 * @return true si le jeton est un et, false sinon.
					 */
					bool estEt() const;

					/**
					 * Indique si le jeton est un alors.
					 * @return true si le jeton est un alors, false sinon.
					 */
					bool estAlors() const;

					/**
					 * Indique si le jeton est une virgule.
					 *@return true si le jeton est une virgule, false sinon.
					 */
					bool estSeparateur() const;

					/**
					 * Indique si le jeton est inconnu.
					 * @return true si le jeton est un inconnu, false sinon.
					 */
					bool estInconnu() const;

					/**
					 * Indique si le jeton est fin du fichier.
					 * @return true si le jeton est fin du fichier, false sinon.
					 */
					bool estFinFichier() const;

					/**
					 * Indique si le jeton est un entier.
					 * @return true si le jeton est un entier, false sinon.
					 */
					bool estEntier() const;

					/**
					 * Indique si le jeton est un supérieur ou égal.
					 * @return true si le jeton est un supérieur ou égal, false sinon.
					 */
					bool estSupEgal() const;

					/**
					 * Indique si le jeton est un inférieur ou égal.
					 * @return true si le jeton est un inférieur ou égal, false sinon.
					 */
					bool estInfEgal() const;

					/**
					 * Indique si le jeton est un différent.
					 * @return true si le jeton est un différent, false sinon.
					 */
					bool estDifferent() const;

					/**
					 * Indique si le jeton est fait_booleen.
					 *@return true si le jeton est fait_booleen, false sinon.
					 */
					bool estFaitBool() const;

					/**
					 * Indique si le jeton est fait_symbolique.
					 * @return true si le jeton est fait_symbolique, false sinon.
					 */
					bool estFaitSymb() const;

					/**
					 * Indique si le jeton est fait_entier.
					 * @return true si le jeton est fait_entier, false sinon.
					 */
					bool estFaitEnt() const;

				private:
					friend class FabriqueJeton;
					/**
					  * Constructeur de la classe FabriqueJeton
	                  * @param [in] typeJeton  type du jeton.
	                  * @param [in] representation  répresentation textuelle du jeton.
	                  */
					Jeton(const TypeJeton & typeJeton, const std::string & representation);
				protected:
					/**
					 * Type du jeton.
					 */
					TypeJeton type_;

					/**
					 * Représentation du jeton.
					 */
					 std::string representation_;
			};
		}
	}
}
#endif
