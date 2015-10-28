#include "fabriqueJeton.hpp"


namespace sysexp{
	
	namespace builders{
		
		FabriqueJeton::FabriqueJeton():
			parentheseOuvrante_(Jeton(type::parentheseOuvrante, "(")),
			parentheseFermante_(Jeton(type::parentheseFermante, ")")),
			superieur_(Jeton(type::superieur, ">")),
			inferieur_(Jeton(type::inferieur, "<")),
			operateurPlus_(Jeton(type::operateurPlus, "+")),
			operateurMoins_(Jeton(type::operateurMoins, "-")),
			operateurMul_(Jeton(type::operateurMul, "*")),
			operateurDiv_(Jeton(type::operateurDiv, "/")),
			egal_(Jeton(type::egal, "=")),
			finExpression_(Jeton(type::finExpression, ";")),
			si_(Jeton(type::si, "si")),
			non_(Jeton(type::non, "non")),
			et_(Jeton(type::et, "et")),
			alors_(Jeton(type::alors, "alors")),
			separateur_(Jeton(type::separateur, ","))
			{}
		
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
			return operateurPlus_;
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
			return finExpression_;
		}
		const Jeton 
		FabriqueJeton::separateur(){
			return separateur_;
		}
		
	}
}
