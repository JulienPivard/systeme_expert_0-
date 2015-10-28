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
					egal, finExpression, faitBooleen, faitEntier, faitSymbolique,
					si, non, et, alors, separateur, inconnu}Type;
	}
	 /**
	   * @namespace sysexp::builders
	   * 
	  **/
	 namespace builders{
		/**
		 * @class Jeton Jeton.hpp
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
				bool estParentheseOuvrante();
				
				/**
				 * Indique si le jeton est une parenthese fermante.
				 */
				bool estParentheseFermante();
				
				/**
				 * Indique si le jeton est superieur.
				 */
				bool estSuperieur();
				
				/**
				 * Indique si le jeton est inferieur.
				 */
				bool estInferieur();
				
				/**
				 * Indique si le jeton est un plus.
				 */
				bool estOperateurPlus();
				
				/**
				 * Indique si le jeton est un moins.
				 */
				bool estOperateurMoins();
				
				/**
				 * Indique si le jeton est un fois.
				 */
				bool estOperateurMul();
				
				/**
				 * Indique si le jeton est un div.
				 */
				bool estOperateurDiv();
				
				/**
				 * Indique si le jeton est un egal
				 */
				bool estEgal();
				
				/**
				 * Indique si le jeton est un point virgule.
				 */
				bool estFinExpression();
				
				/**
				 * Indique si le jeton est un fait booleen.
				 */
				bool estFaitBooleen();
				
				/**
				 * Indique si le jeton est un fait entier.
				 */
				bool estFaitEntier();
				
				/**
				 * Indique si le jeton est un fait symbolique.
				 */
				bool estFaitSymbolique();
				
				/**
				 * Indique si le jeton est un si .
				 */
				bool estSi();
				
				/**
				 * Indique si le jeton est un non.
				 */
				bool estNon();
				
				
				/**
				 * Indique si le jeton est un et.
				 */
				bool estEt();
				
				/**
				 * Indique si le jeton est un alors.
				 */
				bool estAlors();
				
				/**
				 * Indique si le jeton est une virgule .
				 */
				bool estSeparateur();
				
				/**
				 * Indique si le jeton est inconnu.
				 */
				bool estInconnu();
			
			public:
				/**
				 * Constructeur de Jeton.
				 * A CHANGER EN PROTECTED.
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
