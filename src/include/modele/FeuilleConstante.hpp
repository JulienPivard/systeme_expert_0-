/**
 * @file FeuilleConstante.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier FeuilleConstante.cpp.
 * Définit la classe concrète FeuilleConstante.
 * */


#ifndef feuilleconstante_hpp
#define feuilleconstante_hpp

#include <cstdlib>

#include "BaseFait.hpp"
#include "ValeurAbstraite.hpp"

/**
 * @namespace sysexp
 * // namespace global de l'application.
 * */
namespace sysexp
{
    /**
     * @namespace sysexp::modele
     * // namespace modele de l'application.
     * */
    namespace modele
    {

        /**
        * @class FeuilleConstante FeuilleConstante.hpp
        * @brief Permet de représenter une valeur, seule ou dans une partie gauche ou droite d'une opération.
        *
        * Déclaration de la classe FeuilleConstante.
        * */
        class FeuilleConstante : public ValeurAbstraite
        {

            public:

                /**
                 * @typedef PtrFeuilleConstante
                 *
                 * Un shared_ptr sur une feuille constante.
                 * */
                typedef std::shared_ptr< FeuilleConstante > PtrFeuilleConstante;

            public:

                /**
                * Constructeur logique
                *
                * @param[in] valeur
                * La @ref valeur_ de notre feuille.
                * */
                FeuilleConstante( const long int & valeur );

                /**
                 * Permet d'évaluer la valeur de l'objet.
                 *
                 * @param[in] baseFait
                 * La base de faits à utiliser pour évaluer les expressions.
                 *
                 * @return La @ref valeur_ de la feuille.
                 * */
                long int
                interpret( const BaseFait & baseFait ) const;

            protected:

                /**
                * La valeur de notre feuille.
                * */
                const long int valeur_;

        };

    }
}

#endif
