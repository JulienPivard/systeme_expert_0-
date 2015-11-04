/**
 * @file OperateurPlus.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier OperateurPlus.cpp.
 * Définit la classe concrète OperateurPlus.
 * */


#ifndef operateurplus_hpp
#define operateurplus_hpp

#include <cstdlib>

#include "OperateurAbstrait.hpp"
#include "BaseFait.hpp"

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
         * @class OperateurPlus OperateurPlus.hpp
         *
         * Déclaration de la classe OperateurPlus.
         * */
        class OperateurPlus : public OperateurAbstrait
        {

            public:

                /**
                 * @typedef PtrOperateurPlus
                 *
                 * Un shared_ptr sur l'opérateur addition.
                 * */
                typedef std::shared_ptr< OperateurPlus > PtrOperateurPlus;

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] filsGauche
                 * Le fils gauche de l'opération. Voir @ref filsGauche_.
                 * @param[in] filsDroit
                 * Le fils droit de l'opération. Voir @ref filsDroit_.
                 * */
                OperateurPlus( const ValeurAbstraite::Valeur & filsGauche, const ValeurAbstraite::Valeur & filsDroit );

                /**
                 * Permet d'évaluer la valeur de l'opération addition.
                 *
                 * @param[in] baseFait
                 * La base de fait à utiliser pour évaluer les expressions.
                 * @return La valeur de l'opération d'addition.
                 * */
                long int interpret( const BaseFait & baseFait ) const override;

        };

    }
}

#endif
