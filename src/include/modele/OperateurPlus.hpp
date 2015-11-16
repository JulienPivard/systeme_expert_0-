/**
 * @file OperateurPlus.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier OperateurPlus.cpp.
 * Définit la classe concrète OperateurPlus.
 * */


#ifndef operateurplus_hpp
#define operateurplus_hpp

#include <cstdlib>

#include "OperateurAbstrait.hpp"
#include "BaseFait.hpp"


namespace sysexp
{

    namespace modele
    {

        /**
         * @brief Représente une opération d'addition.
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
                 * Le @ref filsGauche_ de l'opération.
                 * @param[in] filsDroit
                 * Le @ref filsDroit_ de l'opération.
                 *
                 * @see ValeurAbstraite
                 * */
                OperateurPlus( const ValeurAbstraite::PtrValeur & filsGauche, const ValeurAbstraite::PtrValeur & filsDroit );

                /**
                 * Permet d'évaluer la valeur de l'opération addition.
                 *
                 * @param[in] baseFait
                 * La base de faits à utiliser pour évaluer les expressions.
                 *
                 * @return Le résultat de l'opération d'addition.
                 * */
                long int interpret( const BaseFait & baseFait ) const override;

            public:

                OperateurPlus( const OperateurPlus & autre ) = delete;

                OperateurPlus & operator=( const OperateurPlus & autre ) = delete;

        };

    }
}

#endif
