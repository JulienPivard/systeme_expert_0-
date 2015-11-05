#include "jeton.hpp"


namespace sysexp{
	
	namespace builders{

		Jeton::Jeton(const type::Type & typeJeton, const std::string& representation):
			type_(typeJeton), representation_(representation){}
		
		const type::Type& 
		Jeton::lireType() const {
		  return type_;
		}

		const std::string& 
		Jeton::lireRepresentation() const {
		  return representation_;
		  
		  
		}

		bool 
		Jeton::estParentheseOuvrante() const {
			return type_ == type::parentheseOuvrante;
		}

		bool 
		Jeton::estParentheseFermante() const {
			return type_ == type::parentheseFermante;
		}

		bool 
		Jeton::estSuperieur() const {
			return type_ == type::superieur;
		}

		bool 
		Jeton::estInferieur() const {
			return type_ == type::inferieur;
		}

		bool 
		Jeton::estOperateurPlus() const {
			return type_ == type::operateurPlus;
		}

		bool 
		Jeton::estOperateurMoins() const {
			return type_ == type::operateurMoins;
		}

		bool 
		Jeton::estOperateurMul() const {
			return type_ == type::operateurMul;
		}

		bool 
		Jeton::estOperateurDiv() const {
			return type_ == type::operateurDiv;
		}

		bool 
		Jeton::estEgal() const {
			return type_ == type::egal;
		}

		bool 
		Jeton::estFinExpression() const {
			return type_ == type::finExpression;
		}

		bool 
		Jeton::estIdentificateur() const {
			return type_ == type::identificateur;
		}

		bool 
		Jeton::estSi() const {
			return type_ == type::si;
		}

		bool 
		Jeton::estNon() const {
			return type_ ==type::non;
		}
		
		bool 
		Jeton::estEt() const {
			return type_ ==type::et;
		}

		bool 
		Jeton::estAlors() const {
			return type_ == type::alors;
		}

		bool 
		Jeton::estSeparateur() const {
			return type_ == type::separateur;
		}

		bool 
		Jeton::estInconnu() const {
			return type_ == type::inconnu;
		}
		
		bool
		Jeton::estFinFichier() const{
			return type_ == type::finFichier;
		}
		
		bool
		Jeton::estEntier() const{
			return type_ == type::entier;
		}

	}
}
