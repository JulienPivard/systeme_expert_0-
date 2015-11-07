/**
 * @file OperateurDiv.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier OperateurDiv.cpp.
 * Définit la classe concrète OperateurDiv.
 * */


#ifndef operateurdiv_hpp
#define operateurdiv_hpp

#include "OperateurAbstrait.hpp"
#include "ExceptionDivParZero.hpp"

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
         * @class OperateurDiv OperateurDiv.hpp
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
                 * Le fils gauche de l'opération. Voir @ref filsGauche_.
                 * @param[in] filsDroit
                 * Le fils droit de l'opération. Voir @ref filsDroit_.
                 * */
                OperateurDiv( const ValeurAbstraite::PtrValeur & filsGauche, const ValeurAbstraite::PtrValeur & filsDroit );

                /**
                 * Permet d'évaluer la valeur de l'opération division.
                 *
                 * @param[in] baseFait
                 * La base de fait à utiliser pour évaluer les expressions.
                 * @return La valeur de l'opération.
                 * @throws ExceptionDivParZero
                 * La partie droite de la division est 0. L'opération ne peut pas être évalué.
                 * */
                long int interpret( const BaseFait & baseFait ) const override;

        };

    }
}

#endif
