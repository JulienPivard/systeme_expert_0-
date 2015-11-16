#include "ParseException.hpp"

namespace sysexp{

	 namespace builders{

	 	namespace lorraine{
	 	
		 	ParseException::ParseException(std::string erreur):
			 	erreur_(erreur)
		 	{}

		 	const char*
		 	ParseException::what() const throw(){
		 		return erreur_.c_str();
		 	}
		}
	}
}