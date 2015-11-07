/**
 * @file OperateurMul.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier OperateurMul.cpp.
 * Définit la classe concrète OperateurMul.
 * */


#ifndef operateurmul_hpp
#define operateurmul_hpp

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
         * @class OperateurMul OperateurMul.hpp
         *
         * Déclaration de la classe OperateurMul.
         * */
        class OperateurMul : public OperateurAbstrait
        {

            public:

                /**
                 * @typedef PtrOperateurMul
                 *
                 * Un shared_ptr de l'opérateur multiplication.
                 * */
                typedef std::shared_ptr< OperateurMul > PtrOperateurMul;

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] filsGauche
                 * Le fils gauche de l'opération. Voir @ref filsGauche_.
                 * @param[in] filsDroit
                 * Le fils droit de l'opération. Voir @ref filsDroit_.
                 * */
                OperateurMul( const ValeurAbstraite::PtrValeur & filsGauche, const ValeurAbstraite::PtrValeur & filsDroit );

                /**
                 * Permet d'évaluer la valeur de l'opération multiplication.
                 *
                 * @param[in] baseFait
                 * La base de fait à utiliser pour évaluer les expressions.
                 * @return La valeur de l'opération de multiplication.
                 * */
                long int interpret( const BaseFait & baseFait ) const override;

        };

    }
}

#endif
