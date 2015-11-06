#ifndef Syntaxique_hpp
#define Syntaxique_hpp

#include "jeton.hpp"
#include "fabriqueJeton.hpp"
#include "lexical.hpp"
#include <string>


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
				* Analyse l'expression connectee a l'analyseur lexical.
				*
				* @return true si l'expression est syntaxiquement correcte sinon false.
				* 
				*/
				bool verifier();
			
			protected:
				/**
				* Methode associee a la regle "Expression".
				*
				* @return true si la regle est satisfaite sinon false.
				* 
				*/
				bool estExpression();
				
				/**
				* Methode associee a la regle "Terme".
				*
				* @return true si la regle est satisfaite sinon false.
				*/
				bool estTerme();
				
				/**
				* Methode associee a la regle "Facteur".
				*
				* @return true si la regle est satisfaite sinon false.
				*/
				bool estFacteur();
				
			protected:
				/**
				* Analyseur lexical.
				*/
				const Lexical lexical;
				/**
				* Dernier jeton precharge.
				*/
				Jeton precharge;
		};
	}
}
#endif
