#ifndef Jeton_hpp
#define Jeton_hpp

#include <string>


/**
 * @namespace sysexp
 *
 **/
 namespace sysexp{


	 namespace type{
		 /**
		  * Type enumere fortement type representant les differentes types de
		  * jetons.
		  */
		 typedef enum {parentheseOuvrante, parentheseFermante, superieur, inferieur,
					operateurPlus, operateurMoins, operateurMul, operateurDiv,
					egal, finExpression, identificateur, entier,
					si, non, et, alors, separateur, inconnu, finFichier, supEgal, infEgal, different, 
					faitBool, faitSymb, faitEnt}Type;
	}
	 /**
	   * @namespace sysexp::builders
	   *
	  **/
	 namespace builders{
		/**
		 * @class Jeton jeton.hpp
		 * Classe representant un jeton de la grammaire.
		 *
		 */
		class Jeton{

			public:
				/**
				 * Accesseur.
				 *
				 * @return la valeur de @ref type_.
				 */
				const type::Type & lireType() const;

				/**
				 * Accesseur.
				 *
				 * @return la valeur de @ref representation_.
				 */
				const std::string& lireRepresentation() const;

				/**
				 * Indique si le jeton est une parenthese ouvrante.
				 * @retval TRUE si le jeton est une parenthese ouvrante.
				 * @retval FALSE si le jeton n'est pas une parenthese ouvrante.
				 */
				bool estParentheseOuvrante() const;

				/**
				 * Indique si le jeton est une parenthese fermante.
				 * @retval TRUE si le jeton est une parenthese fermante.
				 * @retval FALSE si le jeton n'est pas une parenthese fermante.
				 */
				bool estParentheseFermante() const;

				/**
				 * Indique si le jeton est superieur.
				 * @retval TRUE si le jeton est un superieur.
				 * @retval FALSE si le jeton n'est pas un superieur.
				 */
				bool estSuperieur() const;

				/**
				 * Indique si le jeton est inferieur.
				 * @retval TRUE si le jeton est un inferieur.
				 * @retval FALSE si le jeton n'est pas un inferieur.
				 */
				bool estInferieur() const;

				/**
				 * Indique si le jeton est un plus.
				 * @retval TRUE si le jeton est un plus.
				 * @retval FALSE si le jeton n'est pas un plus.
				 */
				bool estOperateurPlus() const;

				/**
				 * Indique si le jeton est un moins.
				 * @retval TRUE si le jeton est un moins.
				 * @retval FALSE si le jeton n'est pas un moins.
				 */
				bool estOperateurMoins() const;

				/**
				 * Indique si le jeton est un fois.
				 * @retval TRUE si le jeton est un fois.
				 * @retval FALSE si le jeton n'est pas un fois.
				 */
				bool estOperateurMul() const;

				/**
				 * Indique si le jeton est un div.
				 * @retval TRUE si le jeton est un div.
				 * @retval FALSE si le jeton n'est pas un div.
				 */
				bool estOperateurDiv() const;

				/**
				 * Indique si le jeton est un egal
				 * @retval TRUE si le jeton est un egal.
				 * @retval FALSE si le jeton n'est pas un egal.
				 */
				bool estEgal() const;

				/**
				 * Indique si le jeton est un point virgule.
				 * @retval TRUE si le jeton est un point virgule.
				 * @retval FALSE si le jeton n'est pas un point virgule.
				 */
				bool estFinExpression() const;

				/**
				 * Indique si le jeton est un identificateur.
				 * @retval TRUE si le jeton est un identificateur.
				 * @retval FALSE si le jeton n'est pas un identificateur.
				 */
				bool estIdentificateur() const;

				/**
				 * Indique si le jeton est un si .
				 * @retval TRUE si le jeton est un si.
				 * @retval FALSE si le jeton n'est pas un si.
				 */
				bool estSi() const;

				/**
				 * Indique si le jeton est un non.
				 * @retval TRUE si le jeton est un non.
				 * @retval FALSE si le jeton n'est pas un non.
				 */
				bool estNon() const;


				/**
				 * Indique si le jeton est un et.
				 * @retval TRUE si le jeton est un et.
				 * @retval FALSE si le jeton n'est pas un et.
				 */
				bool estEt() const;

				/**
				 * Indique si le jeton est un alors.
				 * @retval TRUE si le jeton est un alors.
				 * @retval FALSE si le jeton n'est pas un alors.
				 */
				bool estAlors() const;

				/**
				 * Indique si le jeton est une virgule.
				 * @retval TRUE si le jeton est une vigule.
				 * @retval FALSE si le jeton n'est pas une virgule.
				 */
				bool estSeparateur() const;

				/**
				 * Indique si le jeton est inconnu.
				 * @retval TRUE si le jeton est un inconnu.
				 * @retval FALSE si le jeton n'est pas un inconnu.
				 */
				bool estInconnu() const;
				
				/**
				 * Indique si le jeton est fin du fichier.
				 * @retval TRUE si le jeton est fin du fichier.
				 * @retval FALSE si le jeton n'est pas fin du fichier.
				 */
				bool estFinFichier() const;
				
				/**
				 * Indique si le jeton est un entier.
				 * @retval TRUE si le jeton est un entier.
				 * @retval FALSE si le jeton n'est pas un entier.
				 */
				bool estEntier() const;

				/**
				 * Indique si le jeton est un superieur ou egal.
				 * @retval TRUE si le jeton est un superieur ou egal.
				 * @retval FALSE si le jeton n'est pas un superieur ou egal.
				 */
				bool estSupEgal() const;

				/**
				 * Indique si le jeton est un inferieur ou egal.
				 * @retval TRUE si le jeton est un inferieur ou egal.
				 * @retval FALSE si le jeton n'est pas un inferieur ou egal.
				 */
				bool estInfEgal() const;

				/**
				 * Indique si le jeton est un different.
				 * @retval TRUE si le jeton est un different.
				 * @retval FALSE si le jeton n'est pas un different.
				 */
				bool estDifferent() const;

				/**
				 * Indique si le jeton est fait_booleen.
				 * @retval TRUE si le jeton est fait_booleen.
				 * @retval FALSE si le jeton est fait_booleen
				 */
				bool estFaitBool() const;

				/**
				 * Indique si le jeton est fait_symbolique.
				 * @retval TRUE si le jeton est fait_symbolique.
				 * @retval FALSE si le jeton est fait_symbolique.
				 */
				bool estFaitSymb() const;

				/**
				 * Indique si le jeton est fait_entier.
				 * @retval TRUE si le jeton est fait_entier.
				 * @retval FALSE si le jeton est fait_entier.
				 */
				bool estFaitEnt() const;

			private:
				friend class FabriqueJeton;
				/**
				  * Constructeur de la classe FabriqueJeton
                  * @param [in] typeJeton  type du jeton.
                  * @param [in] representation  representation textuelle du jeton.
                  */
				Jeton(const type::Type & typeJeton, const std::string & representation);
			protected:
				/**
				 * Type du jeton.
				 */
				type::Type type_;
				
				/**
				 * Representation du jeton.
				 */
				 std::string representation_;
		};
	}
}
#endif
