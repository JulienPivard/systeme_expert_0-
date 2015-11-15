/**
 * @file directeur.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
 *
 * Header pour le fichier directeur.cpp.
 * Définit la classe Directeur.
 * */

#ifndef Directeur_hpp
#define Directeur_hpp

#include "builder.hpp"

 /// Paquetage maitre du système expert.
 namespace sysexp{
	 /**
	   * @namespace sysexp::builders
	   * // namespace builders de l'application.
	  **/
	 namespace builders{

		/**
		 * @class Directeur directeur.hpp
		 * @brief Directeur de la construction de la base de règles.
		 * Classe représentant le directeur du builder.
		 *
		 */
		class Directeur {
			public:
				/**
                 * @typedef PtrBuilder
                 *
                 * Le shared pointer sur le builder.
                 * */
				typedef std::shared_ptr<Builder> PtrBuilder;

			public:
				/**
				* Constructeur du Directeur.
                * @param[in] builder
                * Le builder utilisé pour construire la base de règles.
				*/
				Directeur(const PtrBuilder & builder);

			public:
				/**
				* Accesseur.
				* @return un pointeur vers le builder courant.
				*/
				PtrBuilder getBuilder() const;

				/**
				* Mutateur.
				* @param[in] builder
                * Le nouveau @ref builder_.
				*/
				void setBuilder(const PtrBuilder & builder);

				/**
				* Méthode qui permet de construire une base de règle.
				*/
				void construire();

				/**
				* Méthode qui livre une base de règle.
				* @return une base de règle.
				*/
				sysexp::modele::RegleAbstraite::PtrRegleAbstraite livrer();

			protected:

				/**
				* Pointeur sur le builder.
				*/
				PtrBuilder  builder_;
		};
	}
}
#endif
