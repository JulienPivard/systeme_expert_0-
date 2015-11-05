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
					si, non, et, alors, separateur, inconnu, finFichier}Type;
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
				 */
				bool estParentheseOuvrante() const;

				/**
				 * Indique si le jeton est une parenthese fermante.
				 */
				bool estParentheseFermante() const;

				/**
				 * Indique si le jeton est superieur.
				 */
				bool estSuperieur() const;

				/**
				 * Indique si le jeton est inferieur.
				 */
				bool estInferieur() const;

				/**
				 * Indique si le jeton est un plus.
				 */
				bool estOperateurPlus() const;

				/**
				 * Indique si le jeton est un moins.
				 */
				bool estOperateurMoins() const;

				/**
				 * Indique si le jeton est un fois.
				 */
				bool estOperateurMul() const;

				/**
				 * Indique si le jeton est un div.
				 */
				bool estOperateurDiv() const;

				/**
				 * Indique si le jeton est un egal
				 */
				bool estEgal() const;

				/**
				 * Indique si le jeton est un point virgule.
				 */
				bool estFinExpression() const;

				/**
				 * Indique si le jeton est un identificateur.
				 */
				bool estIdentificateur() const;

				/**
				 * Indique si le jeton est un si .
				 */
				bool estSi() const;

				/**
				 * Indique si le jeton est un non.
				 */
				bool estNon() const;


				/**
				 * Indique si le jeton est un et.
				 */
				bool estEt() const;

				/**
				 * Indique si le jeton est un alors.
				 */
				bool estAlors() const;

				/**
				 * Indique si le jeton est une virgule .
				 */
				bool estSeparateur() const;

				/**
				 * Indique si le jeton est inconnu.
				 */
				bool estInconnu() const;
				
				/**
				 * Indique si le jeton est fin du fichier.
				 */
				bool estFinFichier() const;
				
				/**
				 * Indique si le jeton est fin du fichier.
				 */
				bool estEntier() const;

			private:
				friend class FabriqueJeton;
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
