/**
 * @file FeuilleFait.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier FeuilleFait.cpp.
 * Définit la classe abstraite FeuilleFait.
 * */


#ifndef feuillefait_hpp
#define feuillefait_hpp

#include <string>
#include <cstdlib>

#include "BaseFait.hpp"
#include "FaitEntier.hpp"
#include "FaitAbstrait.hpp"
#include "ValeurAbstraite.hpp"
#include "ExceptionFaitInconnu.hpp"

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
        * @class FeuilleFait FeuilleFait.hpp
        *
        * Déclaration de la classe FeuilleFait.
        * */
        class FeuilleFait : public ValeurAbstraite
        {

            public:

                /**
                 * Constructeur logique.
                 *
                 * @param[in] nom
                 * Le @ref nom_ du fait entier dont on veut la valeur.
                 * */
                FeuilleFait( const std::string & nom );

                /**
                 * Permet d'évaluer la valeur de l'objet.
                 *
                 * @param[in] baseFait
                 * La base de fait à utiliser pour évaluer les expressions.
                 * */
                long int
                interpret( const BaseFait & baseFait ) const;

            protected:
                /**
                * Le nom du fait.
                * */
                std::string nom_;

        };

    }
}

#endif
