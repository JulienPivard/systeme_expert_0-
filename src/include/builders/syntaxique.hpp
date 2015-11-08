#ifndef Syntaxique_hpp
#define Syntaxique_hpp

#include "lexical.hpp"
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

				void parser();

				void declarations();

				void declarations_bool();

				void declarations_symb();

				void declarations_ent();

				void listeFaits(std::string valeur);
				
				void regles();

				void regle();

				void regle_sans_premisse();

				void conclusion();

				void conclusion_booleenne();

				void conclusion_symbolique();

				void conclusion_entiere();

				void regle_avec_premisse();
				
			protected:
				/**
				* Analyseur lexical.
				*/
				Lexical & lexical_;
				/**
				* Dernier jeton precharge.
				*/
				Jeton precharge_;

				std::map <std::string, std::string> faits_;


		};
	}
}
#endif
