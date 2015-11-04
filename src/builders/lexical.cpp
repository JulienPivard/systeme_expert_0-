#include "lexical.hpp"

namespace sysexp{

	 namespace builders{
		
		Lexical::Lexical(const std::string & nomFichier):
			ligne_(""),
			position_(0),
			nomFichier_(nomFichier)
			{}
		
		
		const std::string &
		Lexical::lireNomFichier(){
			return nomFichier_;
		}
		
		const std::string &
		Lexical::lireLigne(){
			return ligne_;
		}
		
		unsigned int 
		Lexical::lirePosition(){
			return position_;
		}
			
		bool
		Lexical::avancer(){
			std::string ligne = ligne_;
			std::ifstream fichier(nomFichier_);
			while(true){
				while (position_ < ligne.size() && 
					isspace(ligne.at(position_))) {
					position_ ++;
				}
				 if (position_ == ligne.size()) {
					std::getline(fichier,ligne);
					if (fichier.eof()) {
						return false;
					}
				position_ = 0;
				}
				else{
					return true;
				}
			}
		}
		
		const Jeton 
		Lexical::suivant(){
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
				
			case '>':
				position_ ++;
				return FabriqueJeton::superieur();
			case '<':
				position_ ++;
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
				return FabriqueJeton::operateurDiv();
				
			case '=':
				position_ ++;
				return FabriqueJeton::egal();
			case ';':
				position_ ++;
				return FabriqueJeton::finExpression();
				
			case ',':
				position_ ++;
				return FabriqueJeton::separateur();
			/*
			case 'non': 
				position_ ++;
				return FabriqueJeton::non();
				
			case 'et':
				position_ ++; 
				return FabriqueJeton::et();
				
			case 'alors':
				position_ ++;
				return FabriqueJeton::alors();
			*/	
			
			default: // mot ou entier ou  bien representation inconnue.
				// si
				if(estSi(caractere, position_ )){
					return FabriqueJeton::si();
				}
				// non
				if(estNon(caractere, position_ )){
					return FabriqueJeton::non();
				}
				// et
				if(estEt(caractere, position_ )){
					return FabriqueJeton::et();
				}
				// alors
				if(estAlors(caractere, position_ )){
					return FabriqueJeton::et();
				}
				// entier
				if (isdigit(caractere)) {
				return extraireEntier();
				}
				// C'est la representation inconnue.
				position_ ++;
				return FabriqueJeton::inconnu(ligne_.substr(position_ - 1, 
									 position_));
			
			}
		}
		bool
		Lexical::estSi(char & caractere, unsigned int & position){
			if(caractere == 's'){
				position ++;
				if( caractere == 'i'){
					position ++;
					if(caractere == ' '){
						position ++;
						return true;
					}
				}
			}
			return false;
		}
		
		bool
		Lexical::estNon(char & caractere, unsigned int & position){
			if(caractere == 'n'){
				position ++;
				if( caractere == 'o'){
					position ++;
					if(caractere == 'n'){
						position ++;
						if(caractere == ' '){
							position ++;
							return true;
						}
					}
				}
			}
			return false;
		}
		
		bool
		Lexical::estEt(char & caractere, unsigned int & position){
			if(caractere == 'e'){
				position ++;
				if( caractere == 't'){
					position ++;
					if(caractere == ' '){
						position ++;
						return true;
					}
				}
			}
			return false;
		}		
		
		bool
		Lexical::estAlors(char & caractere, unsigned int & position){
			if(caractere == 'a'){
				position ++;
				if( caractere == 'l'){
					position ++;
					if(caractere == 'o'){
						position ++;
						if(caractere == 'r'){
							position ++;
							if(caractere == 's'){
								position ++;
								if(caractere == ' '){
									position ++;
									return true;
								}
							}
						}
					}
				}
			}
			return false;
		}
		
		const Jeton 
		Lexical::extraireEntier() {
			unsigned int fin = position_ + 1;
			while (fin < ligne_.size() && isdigit(ligne_.at(fin))) {
				fin ++;
			}
			int debut = position_;
			position_ = fin;
			return FabriqueJeton::entier(ligne_.substr(debut, fin));

		}
		
	}	
}
