#ifndef MonException_hpp
#define MonException_hpp

#include <exception>
#include "lexical.hpp"
#include <string>
#include <sstream>

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
		  * Classe representant une exception.
          *
          */
        class MonException : public std::exception {
        	public:
				/**
				* Constructeur de l'exception.
				*
				*/ 
        		MonException(Lexical & lexical, std::string erreur);
        	public:
				/**
				* Chaine de caractere renvoyée lors d'une exception.
				*@return une chaine de caractere décrivant l'exception.
				*/ 
        		const char* what() const throw();

        	protected:
				/**
				* le lexical.
				*
				*/ 
        		Lexical & lexical_;
				
				/**
				* la chaine de caractere décrivant l'erreur.
				*
				*/
                std::string erreur_;
        };
    }
}
#endif
