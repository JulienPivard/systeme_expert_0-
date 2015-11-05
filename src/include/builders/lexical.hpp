#ifndef Lexical_hpp
#define Lexical_hpp

#include <iostream>
#include <istream>
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
				Lexical(std::istream & fichier);
				
			  public: 
				std::istream & lireFichier();
				
				std::string & lireLigne();
				
				unsigned int lirePosition();
				
				const Jeton suivant();
				
			  protected:
			  
				bool avancer();
				
				bool estSi(char & caractere, unsigned int & position);
				
				bool estNon(char & caractere, unsigned int & position);
				
				bool estEt(char & caractere, unsigned int & position);
				
				bool estAlors(char & caractere, unsigned int & position);
				
				const Jeton extraireEntier();
				
				const Jeton extraireIdentificateur();
			
			protected: 
				std::string ligne_;
				
				unsigned int position_;
				
				std::istream & fichier_;
          };
     }
}

#endif
