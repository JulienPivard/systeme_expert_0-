#ifndef Directeur_hpp
#define Directeur_hpp

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
		 * @class Directeur
		 * Classe representant le directeur du builder.
		 *
		 */
		class Directeur {
			public:
				/**
                 * @typedef Builder
                 *
                 * Le shared pointer sur le builder.
                 * */
				typedef std::shared_ptr<Builder> PtrBuilder;
				
			public: 
				/**
				*  
				* Constructeur du Directeur.
				*
				*/
				Directeur(const PtrBuilder & builder);
			
			public: 
				/**
				*  accesseur.
				* @return un pointeur vers le builder courant.
				*
				*/
				PtrBuilder getBuilder() const;
				
				/**
				*  mutateur.
				* @param[in] builder
                 * Le nouveau @ref builder_
				*
				*/
				void setBuilder(const PtrBuilder & builder);
				
				/**
				* methode qui permet de construire une base de regle.
				*
				*/
				void construire();
				
				/**
				* méthode qui livre une base de regle.
				* @return une base de regle.
				*
				*/
				sysexp::modele::RegleAbstraite::PtrRegleAbstraite livrer();
				
			protected: 
			
				PtrBuilder  builder_;
		};
	}
}
#endif
