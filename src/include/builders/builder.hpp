#ifndef Builder_hpp
#define Builder_hpp


#include "syntaxique.hpp"

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
		class Builder{

			public:
				virtual void construireJeuDeRegle() = 0;
				
				virtual sysexp::modele::RegleAbstraite::PtrRegleAbstraite getResult() const = 0;
				
			public:
				virtual ~Builder() = default;
			
		};
	}
}

#endif
