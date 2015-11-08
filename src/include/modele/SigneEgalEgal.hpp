/**
 * @file SigneEgalEgal.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier SigneEgalEgal.cpp.
 * Définit la classe abstraite SigneEgalEgal.
 * */


#ifndef signeegalegal_hpp
#define signeegalegal_hpp

#include "SigneAbstrait.hpp"

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
         * @class SigneEgalEgal SigneEgalEgal.hpp
         * @brief Représentation de la comparaison égal égal.
         *
         * Déclaration de la classe SigneEgalEgal.
         * */
        class SigneEgalEgal : public SigneAbstrait
        {

            public:

                /**
                 * Compare deux entiers.
                 *
                 * @param[in] partieGauche
                 * La partie gauche de la comparaison d'entier.
                 * @param[in] partieDroite
                 * La partie droite de la comparaison d'entier.
                 * @return partieGauche == partieDroite
                 * */
                bool comparer( const long int & partieGauche, const long int & partieDroite ) const;

                /**
                 * Compare deux string.
                 *
                 * @param[in] partieGauche
                 * La partie gauche de la comparaison de string.
                 * @param[in] partieDroite
                 * La partie droite de la comparaison de string.
                 * @return partieGauche == partieDroite
                 * */
                bool comparer( const std::string & partieGauche, const std::string & partieDroite ) const;

        };

    }
}

#endif
