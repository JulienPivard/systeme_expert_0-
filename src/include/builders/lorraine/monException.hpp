/**
 * @file monException.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
 *
 * Header pour le fichier monException.cpp.
 * Définit la classe MonException.
 * */

#ifndef MonException_hpp
#define MonException_hpp

#include <exception>
#include "lexical.hpp"
#include <string>
#include <sstream>


namespace sysexp{
 
	namespace builders{

		namespace lorraine{
			/**
			  * @brief Représente une exception.
	          */
	        class MonException : public std::exception {
	        	public:
					/**
					* Constructeur de l'exception.
					*/ 
	        		MonException(Lexical & lexical, std::string erreur);
	        	public:
					/**
					* @return une chaine de caractère décrivant l'exception.
					*/ 
	        		const char* what() const throw();

	        	protected:
					/**
					* Le lexical.
					*/ 
	        		Lexical & lexical_;
					
					/**
					* La chaine de caractère décrivant l'erreur.
					*/
	                std::string erreur_;
	        };
	    }
    }
}
#endif
