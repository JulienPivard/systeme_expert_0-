/**
 * @file SigneAbstrait.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier SigneAbstrait.cpp.
 * Définit la classe abstraite SigneAbstrait.
 * */


#ifndef signeabstrait_hpp
#define signeabstrait_hpp

#include <string>

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
         * @class SigneAbstrait SigneAbstrait.hpp
         * @brief Le squelette du signe de comparaison.
         *
         * Déclaration de la classe SigneAbstrait.
         * */
        class SigneAbstrait
        {

            public:

                /**
                 * Compare deux entiers.
                 *
                 * @param[in] partieGauche
                 * La partie gauche de la comparaison d'entier.
                 * @param[in] partieDroite
                 * La partie droite de la comparaison d'entier.
                 * @return Le résultat de la comparaison de deux entiers.
                 * */
                virtual bool comparer( const long int & partieGauche, const long int & partieDroite ) const = 0;

                /**
                 * Compare deux string.
                 *
                 * @param[in] partieGauche
                 * La partie gauche de la comparaison de string.
                 * @param[in] partieDroite
                 * La partie droite de la comparaison de string.
                 * @return Le résultat de la comparaison de deux string.
                 * */
                virtual bool comparer( const std::string & partieGauche, const std::string & partieDroite ) const = 0;

                /**
                 * Destructeur rendu virtuel
                 * */
                virtual ~SigneAbstrait() = default;
        };

    }
}

#endif
