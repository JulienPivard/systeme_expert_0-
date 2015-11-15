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


namespace sysexp{
	 
	namespace builders{

	 	/// paquetage contenant les composant logiciels associés a la grammaire lorraine.
	 	namespace lorraine{
		
			/**
			 * @brief Représente le builder de le grammaire Lorraine.
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
}





#endif


