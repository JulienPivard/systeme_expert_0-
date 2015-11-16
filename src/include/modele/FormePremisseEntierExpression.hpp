/**
 * @file FormePremisseEntierExpression.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
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


namespace sysexp
{

    namespace modele
    {

        /**
         * @brief Représente la comparaison de la valeur d'un fait et d'une expression.
         *
         * Déclaration de la classe FormePremisseEntierExpression.
         * */
        class FormePremisseEntierExpression : public FormeAbstraitePremisse
        {

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] nomFait
                 * Le @ref nom_ du fait entier dans la comparaison.
                 * @param[in] comparateur
                 * La fonction (@ref signe_) de comparaison pour tester l'expression entière.
                 * @param[in] expression
                 * L'@ref expression_ entière à laquelle on va comparer le fait.
                 * */
                FormePremisseEntierExpression( const std::string & nomFait,
                        FormeAbstraitePremisse::OperateurComparaisonEntier comparateur,
                        const ValeurAbstraite::PtrValeur & expression );

                /**
                 * Méthode de visite.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui va évaluer la prémisse entiere,
                 * de façon nomFait signe valeurExpression.
                 * @see VisiteurFormeAbstrait
                 * */
                void accept( const PtrVisiteurFormeAbstrait & visiteur );

                /**
                 * Permet de tester les valeurs selon l'opérateur de comparaison stocké.
                 *
                 * @param[in] partieGauche
                 * La partie gauche de la comparaison.
                 * @param[in] partieDroite
                 * La partie droite de la comparaison.
                 *
                 * @return Le @ref signe_ de l'opération booléenne à effectuer.
                 * */
                bool test( const long int & partieGauche, const long int & partieDroite ) const;

                /**
                 * Accesseur
                 *
                 * @param[in] baseFait
                 * La base de faits qui va permettre d'évaluer l'expression.
                 * @see BaseFait
                 *
                 * @return La valeur de l'expression.
                 * */
                long int lireValeur( const BaseFait::PtrBaseFait & baseFait ) const;

            public:

                FormePremisseEntierExpression( const FormePremisseEntierExpression & autre ) = delete;

                FormePremisseEntierExpression & operator=( const FormePremisseEntierExpression & autre ) = delete;

            protected:

                /**
                 * Le signe de comparaison
                 * */
                const OperateurComparaisonEntier signe_;

                /**
                 * L'expression de la prémisse entière.
                 * @see ValeurAbstraite
                 * */
                const ValeurAbstraite::PtrValeur expression_;

        };

    }
}

#endif
