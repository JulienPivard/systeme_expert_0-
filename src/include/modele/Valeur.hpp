/**
 * @file Valeur.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier Valeur.cpp.
 * Définit la classe abstraite Valeur.
 * */

#ifndef valeur_hpp
#define valeur_hpp

#include "BaseFait.hpp"

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
         * @class Valeur Valeur.hpp
         *
         * Déclaration de la classe abstraite Valeur.
         * */
        class Valeur
        {

            public:
                Valeur();

                // Surcharge
                Valeur( const Valeur & autre );

                // Assignation d'un autre objet de même classe en valeur.
                Valeur & operator= ( const Valeur & autre );

                // Destructeur
                ~Valeur();

                const long int & interpret( const BaseFait & baseFait ) const;

        };

    }
}

#endif
