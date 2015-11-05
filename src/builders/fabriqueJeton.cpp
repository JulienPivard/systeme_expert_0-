#include "fabriqueJeton.hpp"


namespace sysexp{
	
	namespace builders{
		const Jeton FabriqueJeton::parentheseOuvrante_(Jeton(type::parentheseOuvrante, "("));
		const Jeton FabriqueJeton::parentheseFermante_(Jeton(type::parentheseFermante, ")"));
		const Jeton FabriqueJeton::superieur_(Jeton(type::superieur, ">"));
		const Jeton FabriqueJeton::inferieur_(Jeton(type::inferieur, "<"));
		const Jeton FabriqueJeton::operateurPlus_(Jeton(type::operateurPlus, "+"));
		const Jeton FabriqueJeton::operateurMoins_(Jeton(type::operateurMoins, "-"));
		const Jeton FabriqueJeton::operateurMul_(Jeton(type::operateurMul, "*"));
		const Jeton FabriqueJeton::operateurDiv_(Jeton(type::operateurDiv, "/"));
		const Jeton FabriqueJeton::egal_(Jeton(type::egal, "="));
		const Jeton FabriqueJeton::finExpression_(Jeton(type::finExpression, ";"));
		const Jeton FabriqueJeton::si_(Jeton(type::si, "si"));
		const Jeton FabriqueJeton::non_(Jeton(type::non, "non"));
		const Jeton FabriqueJeton::et_(Jeton(type::et, "et"));
		const Jeton FabriqueJeton::alors_(Jeton(type::alors, "alors"));
		const Jeton FabriqueJeton::separateur_(Jeton(type::separateur, ","));
		const Jeton FabriqueJeton::finFichier_(Jeton(type::finFichier, ""));
		
		
		const Jeton
		FabriqueJeton::identificateur(const std::string & representation){
			return Jeton(type::identificateur, representation);
		}
		
		const Jeton 
		FabriqueJeton::inconnu(const std::string & representation){
			return Jeton(type::inconnu, representation);
		}
		
		const Jeton 
		FabriqueJeton::entier(const std::string & representation){
			return Jeton(type::entier, representation);
		}
		
		const Jeton 
		FabriqueJeton::parentheseOuvrante(){
			return parentheseOuvrante_;
		}
		
		const Jeton 
		FabriqueJeton::parentheseFermante(){
			return parentheseFermante_;
		}
		
		const Jeton 
		FabriqueJeton::superieur(){
			return superieur_;
		}
		
		const Jeton 
		FabriqueJeton::inferieur(){
			return inferieur_;
		}
		
		const Jeton 
		FabriqueJeton::operateurPlus(){
			return operateurPlus_;
		}
		
		const Jeton 
		FabriqueJeton::operateurMoins(){
			return operateurMoins_;
		}
		
		const Jeton 
		FabriqueJeton::operateurMul(){
			return operateurMul_;
		}
		
		const Jeton 
		FabriqueJeton::operateurDiv(){
			return operateurDiv_;
		}
		
		const Jeton 
		FabriqueJeton::egal(){
			return egal_;
		}
		
		const Jeton 
		FabriqueJeton::finExpression(){
			return finExpression_;
		}
		
		const Jeton 
		FabriqueJeton::si(){
			return si_;
		}
		const Jeton 
		FabriqueJeton::non(){
			return non_;
		}
		const Jeton 
		FabriqueJeton::et(){
			return et_;
		}
		const Jeton 
		FabriqueJeton::alors(){
			return alors_;
		}
		const Jeton 
		FabriqueJeton::separateur(){
			return separateur_;
		}
		
		const Jeton 
		FabriqueJeton::finFichier(){
			return finFichier_;
		}
	}
}
