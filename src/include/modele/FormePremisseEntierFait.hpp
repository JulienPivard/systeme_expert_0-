/**
 * @file FormePremisseEntierFait.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier FormePremisseEntierFait.cpp.
 * Définit la classe concrète FormePremisseEntierFait.
 * */


#ifndef formepremisseentierfait_hpp
#define formepremisseentierfait_hpp

#include "FormeAbstraitePremisse.hpp"
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
         * @class FormePremisseEntierFait FormePremisseEntierFait.hpp
         *
         * Déclaration de la classe FormePremisseEntierFait.
         * */
        class FormePremisseEntierFait : public FormeAbstraitePremisse
        {

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] nomFait
                 * Le nom du fait entier dans la comparaison.
                 * @param[in] comparateur
                 * L'opérateur de comparaison pour tester l'expression entière.
                 * @param[in] nomAutreFait
                 * Le nom du fait dont on veut récupérer la valeur pour la comparer.
                 * */
                FormePremisseEntierFait( const std::string & nomFait,
                        FormeAbstraitePremisse::OperateurComparaison comparateur,
                        const std::string & nomAutreFait );

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
                const std::string & lireNomAutreFait() const;

            protected:

                /**
                 * Le signe de comparaison
                 * */
                const OperateurComparaison signe_;

                /**
                 * L'expression de la prémisse entière.
                 * */
                const std::string nomAutreFait_;

        };

    }
}

#endif
