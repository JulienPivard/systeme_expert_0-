/**
 * @file concreteBuilderLorraine.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
 *
 * Header pour le fichier concreteBuilderLorraine.cpp.
 * Définit la classe ConcreteBuilderLorraine.
 * */

#ifndef BuilderLorraine_hpp
#define BuilderLorraine_hpp

#include "builder.hpp"

/**
 * @namespace sysexp
 * // namespace global de l'application.
 **/
 namespace sysexp{
	 /**
	   * @namespace sysexp::builders
	   * // namespace builders de l'application.
	  **/
	 namespace builders{
		
		/**
		 * @class ConcreteBuilderLorraine concreteBuilderLorraine.hpp
		 * @brief Représente le builder de le grammaire Lorraine.
		 * Classe représentant le builder de la grammaire Lorraine.
		 */
		class ConcreteBuilderLorraine : public Builder {
			public:

				/**
                * @typedef PtrConcreteBuilderLorraine
                *
          		* Le shared_ptr vers le concrete builder lorraine.
				*/
				typedef std::shared_ptr<ConcreteBuilderLorraine> PtrConcreteBuilderLorraine;
				
			public:
				/**
				* Constructeur du concrete builder Lorraine.
				*/
				ConcreteBuilderLorraine(std::istream & fichier);
			
			public:
				
				/**
				* Méthode qui constuit le jeu de règle.
				*/
				void construireJeuDeRegle() override;
				
				/**
				* Retourne le jeu de règle complet.
				*  @return une base de règle de la grammaire lorraine.
				*/
				sysexp::modele::RegleAbstraite::PtrRegleAbstraite getResult() const override;
			
			protected:
				/**
				* Fichier avec lequel les règles seront constuites.
				*/
				std::istream & fichier_;
				
				/**
				* Règle. 
				*/
				sysexp::modele::RegleAbstraite::PtrRegleAbstraite regle_;
		};
	}
}





#endif


