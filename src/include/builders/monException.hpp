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
        		MonException(Lexical & lexical, std::string erreur);
        	public: 
        		const char* what() const throw();

        	protected:
        		Lexical & lexical_;

                std::string erreur_;
        };
    }
}
#endif