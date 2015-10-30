#ifndef Lexical_hpp
#define Lexical_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "jeton.hpp"
#include "fabriqueJeton.hpp"
namespace sysexp{
 
	 /**
	   * @namespace sysexp::builders
	   * 
	  **/
	 namespace builders{
		/**
		  * Classe representant un analyseur lexical de la grammaire.
          *
          */
          class Lexical{
			  public:
				Lexical(const std::string & nomFichier);
				
			  public: 
				//const std::ifstream & lireLecteur();
				
				const std::string & lireLigne();
				
				unsigned int lirePosition();
				
				bool avancer();
				
				const Jeton suivant();
			
			protected: 
				const std::string ligne_;
				
				unsigned int position_;
				
				const std::string & nomFichier_;
          };
     }
}

#endif
