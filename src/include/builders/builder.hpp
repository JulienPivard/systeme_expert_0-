/**
 * @file builder.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
 *
 * Header pour le fichier builder.cpp.
 * Définit la classe Builder.
 * */

#ifndef Builder_hpp
#define Builder_hpp

#include "syntaxique.hpp"


namespace sysexp{

	namespace builders{

		/**
		 * @brief Permet de construire une base de règle.
		 */
		class Builder{

			public:
				/**
				* Méthode abstraite qui constuit un jeu de règle.
				*/
				virtual void construireJeuDeRegle() = 0;

				/**
				* Méthode abstraite.
				*  @return une base de règle d'une grammaire.
				*/
				virtual const sysexp::modele::RegleAbstraite::PtrRegleAbstraite & getResult() const = 0;

			public:
				/**
				* Destructeur.
				*/
				virtual ~Builder() = default;

            public:

                Builder & operator=( const Builder & autre ) = delete;
		};
	}
}

#endif
