/**
 * @file ParseException.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
 *
 * Header pour le fichier parseException.cpp.
 * Définit la classe ParseException.
 * */

#ifndef ParseException_hpp
#define ParseException_hpp

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
	        class ParseException : public std::exception {
	        	public:
					/**
					* Constructeur de l'exception.
					*/ 
	        		ParseException(std::string erreur);
	        	public:
					/**
					* @return une chaine de caractère décrivant l'exception.
					*/ 
	        		const char* what() const throw() override;

	        	protected:					
					/**
					* La chaine de caractère décrivant l'erreur.
					*/
	                std::string erreur_;
	        };
	    }
    }
}
#endif
