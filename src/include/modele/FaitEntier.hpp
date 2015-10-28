/**
 * @file FaitEntier.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier FaitEntier.cpp.
 * Définit la classe FaitEntier.
 * */

#ifndef faitentier_hpp
#define faitentier_hpp

#include "Fait.hpp"

/**
 * @namespace sysexp
 * */
namespace sysexp
{
    /**
    * @namespace sysexp::modele
    * */
    namespace modele
    {

        /**
         * @class FaitEntier FaitEntier.hpp
         *
         * Déclaration de la classe concrète FaitEntier.
         * Cette classe permet de représenter un fait entier et sa valeur.
         * */
        class FaitEntier : public Fait
        {

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
                 * @return La valeur du fait symbolique.
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
