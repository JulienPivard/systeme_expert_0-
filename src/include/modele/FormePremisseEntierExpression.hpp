/**
 * @file FormePremisseEntierExpression.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier FormePremisseEntierExpression.cpp.
 * Définit la classe concrète FormePremisseEntierExpression.
 * */


#ifndef formepremisseentierexpression_hpp
#define formepremisseentierexpression_hpp

#include <string>

#include "FormeAbstraitePremisse.hpp"
#include "ValeurAbstraite.hpp"
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
         * @class FormePremisseEntierExpression FormePremisseEntierExpression.hpp
         * @brief Représente la comparaison de la valeur d'un fait et d'une expression.
         *
         * Déclaration de la classe FormePremisseEntierExpression.
         * */
        class FormePremisseEntierExpression : public FormeAbstraitePremisse
        {

            public:

                /**
                 * @typedef OperateurComparaison
                 *
                 * Le prototype de l'opérateur de comparaison.
                 * */
                typedef bool (&OperateurComparaison)( const long int &, const long int& );

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] nomFait
                 * Le nom du fait entier dans la comparaison.
                 * @param[in] comparateur
                 * L'opérateur de comparaison pour tester l'expression entière.
                 * @param[in] expression
                 * L'expression entière à laquelle on va comparer le fait.
                 * */
                FormePremisseEntierExpression( const std::string & nomFait, OperateurComparaison comparateur, const ValeurAbstraite::PtrValeur & expression );

                /**
                 * Méthode de visite.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui vas évaluer le prémisse entier,
                 * de façon nomFait signe valeurExpression.
                 * */
                void accept( const PtrVisiteurFormeAbstrait & visiteur );

                /**
                 * Accesseur
                 *
                 * @return Le signe de l'opération booléenne à effectuer.
                 * */
                bool test( const long int & partieGauche, const long int & partieDroite ) const;

                /**
                 * Accesseur
                 *
                 * @param[in] baseFait
                 * La base de fait qui vas permettre d'évaluer l'expression.
                 * @return La valeur de l'expression.
                 * */
                long int lireValeur( const BaseFait::PtrBaseFait & baseFait ) const;

            protected:

                /**
                 * Le signe de comparaison
                 * */
                const OperateurComparaison signe_;

                /**
                 * L'expression de la prémisse entière.
                 * */
                const ValeurAbstraite::PtrValeur expression_;

        };

    }
}

#endif
