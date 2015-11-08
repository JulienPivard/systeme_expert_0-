/**
 * @file FeuilleConstante.hpp
 * @brief header.
 * @author PIVARD Julien
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
 * */
namespace sysexp
{
    /**
     * @namespace sysexp::modele
     * */
    namespace modele
    {

        /**
        * @class FeuilleConstante FeuilleConstante.hpp
        * @brief Permet de représenter une valeur, seule ou dans une partie gauche ou droit d'une opération.
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
                 * La base de fait à utiliser pour évaluer les expressions.
                 * @return La valeur de la feuille de l'opération.
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
