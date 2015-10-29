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
		Jeton::estParentheseOuvrante() {
			return type_ == type::parentheseOuvrante;
		}

		bool 
		Jeton::estParentheseFermante() {
			return type_ == type::parentheseFermante;
		}

		bool 
		Jeton::estSuperieur() {
			return type_ == type::superieur;
		}

		bool 
		Jeton::estInferieur() {
			return type_ == type::inferieur;
		}

		bool 
		Jeton::estOperateurPlus() {
			return type_ == type::operateurPlus;
		}

		bool 
		Jeton::estOperateurMoins() {
			return type_ == type::operateurMoins;
		}

		bool 
		Jeton::estOperateurMul() {
			return type_ == type::operateurMul;
		}

		bool 
		Jeton::estOperateurDiv() {
			return type_ == type::operateurDiv;
		}

		bool 
		Jeton::estEgal() {
			return type_ == type::egal;
		}

		bool 
		Jeton::estFinExpression() {
			return type_ == type::finExpression;
		}

		bool 
		Jeton::estIdentificateur() {
			return type_ == type::identificateur;
		}

		bool 
		Jeton::estSi() {
			return type_ == type::si;
		}

		bool 
		Jeton::estNon() {
			return type_ ==type::non;
		}
		
		bool 
		Jeton::estEt() {
			return type_ ==type::et;
		}

		bool 
		Jeton::estAlors() {
			return type_ == type::alors;
		}

		bool 
		Jeton::estSeparateur() {
			return type_ == type::separateur;
		}

		bool 
		Jeton::estInconnu() {
			return type_ == type::inconnu;
		}

	}
}
