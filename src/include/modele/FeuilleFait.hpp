/**
 * @file FeuilleFait.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier FeuilleFait.cpp.
 * Définit la classe concrète FeuilleFait.
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
        * @brief Permet de représenter une variable, seule ou dans une partie gauche ou droit d'une opération.
        *
        * Déclaration de la classe FeuilleFait.
        * */
        class FeuilleFait : public ValeurAbstraite
        {

            public:

                /**
                 * @typedef PtrFeuilleFait
                 *
                 * Un shared_ptr sur une feuille de fait.
                 * */
                typedef std::shared_ptr< FeuilleFait > PtrFeuilleFait;

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
                 *
                 * @return La valeur de la feuille fait.
                 *
                 * @throw ExceptionFaitInconnu
                 * Le fait n'est pas connu dans la base de fait,
                 * la feuille ne peut pas être évaluée dans l'immédiat.
                 * */
                long int
                interpret( const BaseFait & baseFait ) const;

            protected:

                /**
                * Le nom du fait dans lequel se trouve la valeur.
                * */
                const std::string nom_;

        };

    }
}

#endif
