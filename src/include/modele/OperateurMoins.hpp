/**
 * @file OperateurMoins.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier OperateurMoins.cpp.
 * Définit la classe concrète OperateurMoins.
 * */


#ifndef operateurmoins_hpp
#define operateurmoins_hpp

#include <cstdlib>

#include "OperateurAbstrait.hpp"


namespace sysexp
{

    namespace modele
    {

        /**
         * @brief Représente une opération de soustraction.
         *
         * Déclaration de la classe OperateurMoins.
         * */
        class OperateurMoins : public OperateurAbstrait
        {

            public:

                /**
                 * @typedef PtrOperateurMoins
                 *
                 * Un shared_ptr pour l'opérateur de soustraction.
                 * */
                typedef std::shared_ptr< OperateurMoins > PtrOperateurMoins;

            public:

                /**
                 * Constructeur logique.
                 *
                 * @param[in] filsGauche
                 * Le @ref filsGauche_ de l'opération.
                 * @param[in] filsDroit
                 * Le @ref filsDroit_ de l'opération.
                 *
                 * @see ValeurAbstraite
                 * */
                OperateurMoins( const ValeurAbstraite::PtrValeur & filsGauche, const ValeurAbstraite::PtrValeur & filsDroit );

                /**
                 * Permet d'évaluer la valeur de l'opération soustraction.
                 *
                 * @param[in] baseFait
                 * La base de faits à utiliser pour évaluer les expressions.
                 *
                 * @return La résultat de l'opération de soustraction.
                 * */
                long int interpret( const BaseFait & baseFait ) const override;

            public:

                OperateurMoins( const OperateurMoins & autre ) = delete;

                OperateurMoins & operator=( const OperateurMoins & autre ) = delete;

        };
    }

}

#endif
