/**
 * @file FeuilleConstante.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier FeuilleConstante.cpp.
 * Définit la classe abstraite FeuilleConstante.
 * */


#ifndef feuilleconstante_hpp
#define feuilleconstante_hpp

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
        *
        * Déclaration de la classe FeuilleConstante.
        * */
        class FeuilleConstante : public ValeurAbstraite
        {

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
                 * */
                const long int &
                interpret( const BaseFait & baseFait ) const;

            protected:
                /**
                * La valeur de notre feuille.
                * */
                long int valeur_;

        };

    }
}

#endif
