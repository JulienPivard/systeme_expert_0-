/**
 * @file SigneInferieurEgal.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier SigneInferieurEgal.cpp.
 * Définit la classe abstraite SigneInferieurEgal.
 * */


#ifndef signeinferieuregal_hpp
#define signeinferieuregal_hpp

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
         * @class SigneInferieurEgal SigneInferieurEgal.hpp
         * @brief Représentation de la comparaison inférieur égal.
         *
         * Déclaration de la classe SigneInferieurEgal.
         * */
        class SigneInferieurEgal : public SigneAbstrait
        {

            public:

                /**
                 * Compare deux entiers.
                 *
                 * @param[in] partieGauche
                 * La partie gauche de la comparaison d'entier.
                 * @param[in] partieDroite
                 * La partie droite de la comparaison d'entier.
                 * @return partieGauche <= partieDroite
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
