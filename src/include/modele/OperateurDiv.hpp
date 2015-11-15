/**
 * @file OperateurDiv.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
 *
 * Header pour le fichier OperateurDiv.cpp.
 * Définit la classe concrète OperateurDiv.
 * */


#ifndef operateurdiv_hpp
#define operateurdiv_hpp

#include "OperateurAbstrait.hpp"
#include "ExceptionDivParZero.hpp"


namespace sysexp
{
    
    namespace modele
    {

        /**
         * @brief Représente une opération de division.
         *
         * Déclaration de la classe OperateurDiv.
         * */
        class OperateurDiv : public OperateurAbstrait
        {

            public:

                /**
                 * @typedef PtrOperateurDiv
                 *
                 * Un shared_ptr de l'opérateur division.
                 * */
                typedef std::shared_ptr< OperateurDiv > PtrOperateurDiv;

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
                OperateurDiv( const ValeurAbstraite::PtrValeur & filsGauche, const ValeurAbstraite::PtrValeur & filsDroit );

                /**
                 * Permet d'évaluer la valeur de l'opération division.
                 *
                 * @param[in] baseFait
                 * La base de faits à utiliser pour évaluer les expressions.
                 *
                 * @return La résultat de l'opération de division.
                 *
                 * @throws ExceptionDivParZero
                 * La partie droite de la division est 0. L'opération ne peut pas être évaluée.
                 * */
                long int interpret( const BaseFait & baseFait ) const override;

        };

    }
}

#endif
