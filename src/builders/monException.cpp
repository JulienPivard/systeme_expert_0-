#include "monException.hpp"

namespace sysexp{

	 namespace builders{
	 	
	 	MonException::MonException(Lexical & lexical):
	 	lexical_(lexical)
	 	{}

	 	const char*
	 	MonException::what() const throw(){
	 		const std::string ligne = lexical_.lireLigne();
	    	const int position = lexical_.lirePosition();
	    	std::ostringstream message;
	    	message << "Erreur (entre crochets) en ligne : " << 
			lexical_.lireNumeroLigne() <<
			"\n" <<
			ligne.substr(0, position - 1) << 
			"[" <<
			ligne.at(position - 1) <<
			"]" <<
			ligne.substr(position, ligne.size()) <<
			"\n";
	    	
	 		return message.str().c_str();
	 	}
	}
}