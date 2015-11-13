#ifndef BuilderLorraine_hpp
#define BuilderLorraine_hpp

#include "builder.hpp"

/**
 * @namespace sysexp
 *
 **/
 namespace sysexp{
	 /**
	   * @namespace sysexp::builders
	   *
	  **/
	 namespace builders{
		
		/**
		 * @class ConcreteBuilderLorraine 
		 * Classe representant le builder de la grammaire Lorraine.
		 *
		 */
		class ConcreteBuilderLorraine : public Builder {
			public:
			
					typedef std::shared_ptr<ConcreteBuilderLorraine> PtrConcreteBuilderLorraine;
				
			public:
				/**
				*  
				* Constructeur du concrete builder Lorraine.
				*
				*/
				ConcreteBuilderLorraine(std::istream & fichier);
			
			public:
				
				/**
				* 
				* methode qui constuit le jeu de regle
				*
				*/
				void construireJeuDeRegle() override;
				
				/**
				*
				* retourne le jeu de regle complet.
				*  @return une base de regle de la grammaire lorraine.
				*
				*/
				sysexp::modele::RegleAbstraite::PtrRegleAbstraite getResult() const override;
			
			protected:
				/**
				* fichier avec lequel les regles seront constuites
				* 
				*/
				std::istream & fichier_;
				
				/**
				* regle 
				* 
				*/
				sysexp::modele::RegleAbstraite::PtrRegleAbstraite regle_;
				
			
		};
	}
}





#endif


