#include "lexical.hpp"

namespace sysexp{

	 namespace builders{
		
		Lexical::Lexical(std::istream & fichier):
			ligne_(""),
			position_(0),
			fichier_(fichier),
			numeroLigne_(0)
			{}
		
		
		std::istream &
		Lexical::lireFichier(){
			return fichier_;
		}
		
		std::string &
		Lexical::lireLigne(){
			return ligne_;
		}
		
		unsigned int 
		Lexical::lirePosition(){
			return position_;
		}

		int
		Lexical::lireNumeroLigne(){
			return numeroLigne_;
		}
			
		bool
		Lexical::avancer(){
			while(true){
				//tant qu'on est dans la ligne et qu'on rencontre un espace, on passe au suivant.
				while (position_ < ligne_.size() && 
					isspace(ligne_.at(position_))) {
					position_ ++;
				}
				if (position_ == ligne_.size()) {
					if (fichier_.eof()) {
						return false;
					}
					//on récupere la ligne
					std::getline(fichier_,ligne_);
					//on incremente le numéro de ligne
					numeroLigne_ ++;
					// on se place qu début de celle ci
					position_ = 0;
				}
				else{
					return true;
				}
			}
		}
		
		const Jeton 
		Lexical::suivant(){
			// si on ne peut plus avancer on est a la fin du fichier.
			if (!avancer()){
				return FabriqueJeton::finFichier();
			}
			
			char caractere = ligne_.at(position_); 
			
			switch(caractere) {   
		 
			case '(': // Parenthese ouvrante.
				position_ ++;
				return FabriqueJeton::parentheseOuvrante();

			case ')': // Parenthese fermante.
				position_ ++;
				return FabriqueJeton::parentheseFermante();
				
			case '>': //superieur
				position_ ++;
				if (ligne_.at(position_) == '='){
					position_++;
					return FabriqueJeton::supEgal();
				}
				return FabriqueJeton::superieur();
			case '<': //inferieur
				position_ ++;
				if (ligne_.at(position_) == '='){
					position_++;
					return FabriqueJeton::infEgal();
				}
				return FabriqueJeton::inferieur();
				
			case '+': // Operateur d'addition.
				position_ ++;
				return FabriqueJeton::operateurPlus();

			case '-': // Operateur de soustraction.
				position_ ++;
				return FabriqueJeton::operateurMoins();

			case '*': // Operateur de multiplication.
				position_ ++;
				return FabriqueJeton::operateurMul();

			case '/': // Operateur de division.
				position_ ++;
				if (ligne_.at(position_) == '='){
					position_++;
					return FabriqueJeton::different();
				}
				return FabriqueJeton::operateurDiv();
				
			case '=': //egal
				position_ ++;
				return FabriqueJeton::egal();
			case ';': // fin d'expression
				position_ ++;
				return FabriqueJeton::finExpression();
				
			case ',': // séparateur
				position_ ++;
				return FabriqueJeton::separateur();
			
			default: // identificateur ou entier ou bien representation inconnue.
				// entier
				if (isdigit(caractere)) {
					return extraireEntier();
				}
				//identificateur + "si, et, non, alors"
				if(isalpha(caractere)){
					return extraireChaine(); 
				}
				// C'est la representation inconnue.
				position_ ++;
				return FabriqueJeton::inconnu(ligne_.substr(position_ - 1, 1));
			
			}
		}
		
		const Jeton 
		Lexical::extraireEntier() {
			unsigned int fin = position_ + 1;
			while (fin < ligne_.size() && isdigit(ligne_.at(fin))) {
				fin ++;
			}
			int debut = position_;
			position_ = fin;
			return FabriqueJeton::entier(ligne_.substr(debut, fin-debut));

		}
		
		const Jeton 
		Lexical::extraireChaine() {
			unsigned int fin = position_ + 1;
			while (fin < ligne_.size() && (isalnum(ligne_.at(fin)) || ligne_.at(fin) == '_')) {
				fin ++;
			}
			int debut = position_;
			position_ = fin;
			std::string mot = ligne_.substr(debut, fin-debut);
			if(mot == "si"){
				return FabriqueJeton::si();
			}
			else if(mot == "et") {
				return FabriqueJeton::et();
			}
			else if(mot == "non"){
				return FabriqueJeton::non();
			}
			else if(mot == "alors"){
				return FabriqueJeton::alors();
			}
			else if(mot == "faits_booleens"){
				return FabriqueJeton::faitBool();
			}
			else if(mot == "faits_symboliques"){
				return FabriqueJeton::faitSymb();
			}
			else if(mot == "faits_entiers"){
				return FabriqueJeton::faitEnt();
			}
			return FabriqueJeton::identificateur(ligne_.substr(debut, fin-debut));

		}
	}	
}
