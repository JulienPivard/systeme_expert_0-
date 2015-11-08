/**
 * @file SigneSuperieurEgal.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier SigneSuperieurEgal.cpp.
 * Définit la classe abstraite SigneSuperieurEgal.
 * */


#ifndef signesuperieuregal_hpp
#define signesuperieuregal_hpp

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
         * @class SigneSuperieurEgal SigneSuperieurEgal.hpp
         * @brief Représentation de la comparaison supérieur égal.
         *
         * Déclaration de la classe SigneSuperieurEgal.
         * */
        class SigneSuperieurEgal : public SigneAbstrait
        {

            public:

                /**
                 * Compare deux entiers.
                 *
                 * @param[in] partieGauche
                 * La partie gauche de la comparaison d'entier.
                 * @param[in] partieDroite
                 * La partie droite de la comparaison d'entier.
                 * @return partieGauche >= partieDroite
                 * */
                bool comparer( const long int & partieGauche, const long int & partieDroite ) const;

                /**
                 * Compare deux string.
                 * La méthode n'a ici pas de sens.
                 *
                 * @param[in] partieGauche
                 * La partie gauche de la comparaison de string.
                 * @param[in] partieDroite
                 * La partie droite de la comparaison de string.
                 * @return Le résultat de la comparaison de deux string.
                 * */
                bool comparer( const std::string & partieGauche, const std::string & partieDroite ) const;

        };

    }
}

#endif
