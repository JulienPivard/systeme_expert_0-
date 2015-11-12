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

#include <string>

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
         * @brief Représente la comparaison de la valeur d'un fait avec celle d'un autre fait.
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
                 * Le @ref nom_ du premier fait entier que l'on veut comparer.
                 * @param[in] comparateur
                 * L'opérateur (@ref signe_) de comparaison pour tester l'expression entière.
                 * @param[in] nomAutreFait
                 * Le @ref nomAutreFait_ du second fait dont on veut récupérer la valeur pour la comparer à celle du premier fait.
                 * */
                FormePremisseEntierFait( const std::string & nomFait,
                        FormeAbstraitePremisse::OperateurComparaisonEntier comparateur,
                        const std::string & nomAutreFait );

                /**
                 * Méthode de visite.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui vas évaluer le prémisse entier,
                 * de façon valeurFait signe valeurAutreFait.
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
                 * @return Le test partieGauche @ref signe_ partieDroite.
                 * */
                bool test( const long int & partieGauche, const long int & partieDroite ) const;

                /**
                 * Accesseur
                 *
                 * @return Le @ref nomAutreFait_ du fait qui contient la valeur à tester.
                 * */
                const std::string & lireNomAutreFait() const;

            protected:

                /**
                 * Le signe de comparaison
                 * */
                const OperateurComparaisonEntier signe_;

                /**
                 * L'expression de la prémisse entière.
                 * */
                const std::string nomAutreFait_;

        };

    }
}

#endif
