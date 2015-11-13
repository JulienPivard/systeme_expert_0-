#include "directeur.hpp"


 namespace sysexp{
	 
	 namespace builders{
		
		Directeur::Directeur(const PtrBuilder & builder):
			builder_(builder)
			{}
		
		Directeur::PtrBuilder	
		Directeur::getBuilder() const{
			return builder_;
		}
		
		void
		Directeur::setBuilder(const PtrBuilder & builder){
			builder_ = builder;
		}
		
		void
		Directeur::construire(){
			builder_->construireJeuDeRegle();
		}
		
		sysexp::modele::RegleAbstraite::PtrRegleAbstraite
		Directeur::livrer(){
			return builder_->getResult();
		}
	}
}
		
		
