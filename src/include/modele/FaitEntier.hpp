/**
 * @file FaitEntier.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier FaitEntier.cpp.
 * Définit la classe concrète FaitEntier.
 * */

#ifndef faitentier_hpp
#define faitentier_hpp

#include <cstdlib>

#include "FaitAbstrait.hpp"


namespace sysexp
{
    
    namespace modele
    {

        /**
         * @brief Représente un fait entier. Sa valeur ne peut pas être modifiée.
         *
         * Déclaration de la classe concrète FaitEntier.
         * Cette classe permet de représenter un fait entier et sa valeur.
         * */
        class FaitEntier : public FaitAbstrait
        {

            public:

                /**
                 * @typedef PtrFaitEntier
                 *
                 * Nom facile pour un shared_ptr de FaitEntier.
                 * */
                typedef std::shared_ptr< FaitEntier > PtrFaitEntier;

            public:
                /**
                 * Constructeur logique du fait entier.
                 *
                 * @param[in] nom
                 * Le @ref nom_ du fait symbolique.
                 * @param[in] valeur
                 * La @ref valeur_ du fait symbolique.
                 * */
                FaitEntier( const std::string & nom, const long int & valeur );

                /**
                 * Accesseur.
                 *
                 * @return La @ref valeur_ du fait symbolique.
                 * */
                const long int & lireValeur() const;

            protected:

                /**
                 * La valeur de notre fait entier.
                 * La valeur n'est pas censé changer.
                 * */
                const long int valeur_;

        };

    }
}

#endif
