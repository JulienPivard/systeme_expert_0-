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
				/**
				* methode abstraite qui constuit un jeu de regle
				*/
				virtual void construireJeuDeRegle() = 0;
				
				/**
				*
				* retourne un jeu de regle complet.
				*  @return une base de regle d'une grammaire.
				*
				*/
				virtual sysexp::modele::RegleAbstraite::PtrRegleAbstraite getResult() const = 0;
				
			public:
				/**
				* destructeur.
				*/
				virtual ~Builder() = default;
			
		};
	}
}

#endif
