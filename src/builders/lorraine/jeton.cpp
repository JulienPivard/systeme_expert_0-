#include "jeton.hpp"


namespace sysexp{
	
	namespace builders{

		namespace lorraine{

			Jeton::Jeton(const TypeJeton & typeJeton, const std::string& representation):
				type_(typeJeton), representation_(representation){}
			
			const TypeJeton & 
			Jeton::lireType() const {
			  return type_;
			}

			const std::string & 
			Jeton::lireRepresentation() const {
			  return representation_;
			  
			  
			}

			bool 
			Jeton::estParentheseOuvrante() const {
				return type_ == TypeJeton::parentheseOuvrante;
			}

			bool 
			Jeton::estParentheseFermante() const {
				return type_ == TypeJeton::parentheseFermante;
			}

			bool 
			Jeton::estSuperieur() const {
				return type_ == TypeJeton::superieur;
			}

			bool 
			Jeton::estInferieur() const {
				return type_ == TypeJeton::inferieur;
			}

			bool 
			Jeton::estOperateurPlus() const {
				return type_ == TypeJeton::operateurPlus;
			}

			bool 
			Jeton::estOperateurMoins() const {
				return type_ == TypeJeton::operateurMoins;
			}

			bool 
			Jeton::estOperateurMul() const {
				return type_ == TypeJeton::operateurMul;
			}

			bool 
			Jeton::estOperateurDiv() const {
				return type_ == TypeJeton::operateurDiv;
			}

			bool 
			Jeton::estEgal() const {
				return type_ == TypeJeton::egal;
			}

			bool 
			Jeton::estFinExpression() const {
				return type_ == TypeJeton::finExpression;
			}

			bool 
			Jeton::estIdentificateur() const {
				return type_ == TypeJeton::identificateur;
			}

			bool 
			Jeton::estSi() const {
				return type_ == TypeJeton::si;
			}

			bool 
			Jeton::estNon() const {
				return type_ ==TypeJeton::non;
			}
			
			bool 
			Jeton::estEt() const {
				return type_ ==TypeJeton::et;
			}

			bool 
			Jeton::estAlors() const {
				return type_ == TypeJeton::alors;
			}

			bool 
			Jeton::estSeparateur() const {
				return type_ == TypeJeton::separateur;
			}

			bool 
			Jeton::estInconnu() const {
				return type_ == TypeJeton::inconnu;
			}
			
			bool
			Jeton::estFinFichier() const{
				return type_ == TypeJeton::finFichier;
			}
			
			bool
			Jeton::estEntier() const{
				return type_ == TypeJeton::entier;
			}

			bool
			Jeton::estSupEgal() const{
				return type_ == TypeJeton::supEgal;
			}

			bool 
			Jeton::estInfEgal() const{
				return type_ == TypeJeton::infEgal;
			}

			bool
			Jeton::estDifferent() const{
				return type_ == TypeJeton::different;
			}

			bool 
			Jeton::estFaitBool() const{
				return type_ == TypeJeton::faitBool;
			}

			bool
			Jeton::estFaitSymb() const{
				return type_ == TypeJeton::faitSymb;
			}

			bool 
			Jeton::estFaitEnt() const{
				return type_ == TypeJeton::faitEnt;
			}
		}
	}

}
