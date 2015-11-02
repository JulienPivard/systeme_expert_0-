/**
 * @file OperateurMoins.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier OperateurMoins.cpp.
 * Définit la classe concrète OperateurMoins.
 * */


#ifndef operateurmoins_hpp
#define operateurmoins_hpp

#include <cstdlib>

#include "OperateurAbstrait.hpp"

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
         * @class OperateurMoins OperateurMoins.hpp
         *
         * Déclaration de la classe OperateurMoins.
         * */
        class OperateurMoins : public OperateurAbstrait
        {

            public:

                /**
                 * Constructeur logique.
                 *
                 * @param[in] filsGauche
                 * Le fils gauche de l'opération. Voir @ref filsGauche_.
                 * @param[in] filsDroit
                 * Le fils droit de l'opération. Voir @ref filsDroit_.
                 * */
                OperateurMoins( const ValeurAbstraite::Valeur & filsGauche, const ValeurAbstraite::Valeur & filsDroit );

                /**
                 * Permet d'évaluer la valeur de l'opération soustraction.
                 *
                 * @param[in] baseFait
                 * La base de fait à utiliser pour évaluer les expressions.
                 * @return La valeur de l'opération de soustraction.
                 * */
                long int interpret( const BaseFait & baseFait ) const override;

        };
    }

}

#endif
