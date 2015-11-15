/**
 * @file OperateurMul.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
 *
 * Header pour le fichier OperateurMul.cpp.
 * Définit la classe concrète OperateurMul.
 * */


#ifndef operateurmul_hpp
#define operateurmul_hpp

#include <cstdlib>

#include "OperateurAbstrait.hpp"


namespace sysexp
{
    
    namespace modele
    {

        /**
         * @brief Représente une opération de multiplication.
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
                 * Le @ref filsGauche_ de l'opération.
                 * @param[in] filsDroit
                 * Le @ref filsDroit_ de l'opération.
                 *
                 * @see ValeurAbstraite
                 * */
                OperateurMul( const ValeurAbstraite::PtrValeur & filsGauche, const ValeurAbstraite::PtrValeur & filsDroit );

                /**
                 * Permet d'évaluer la valeur de l'opération multiplication.
                 *
                 * @param[in] baseFait
                 * La base de faits à utiliser pour évaluer les expressions.
                 *
                 * @return Le résultat de l'opération de multiplication.
                 * */
                long int interpret( const BaseFait & baseFait ) const override;

        };

    }
}

#endif
