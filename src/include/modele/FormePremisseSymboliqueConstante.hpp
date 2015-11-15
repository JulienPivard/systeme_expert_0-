/**
 * @file FormePremisseSymboliqueConstante.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier FormePremisseSymboliqueConstante.cpp.
 * Définit la classe concrète FormePremisseSymboliqueConstante.
 * */


#ifndef formepremissesymboliqueconstante_hpp
#define formepremissesymboliqueconstante_hpp

#include <string>

#include "FormeAbstraitePremisse.hpp"
#include "BaseFait.hpp"


namespace sysexp
{
    
    namespace modele
    {

        /**
         * @brief Représente la comparaison de la valeur d'un fait symbolique et d'une chaine de caractère.
         *
         * Déclaration de la classe FormePremisseSymboliqueConstante.
         * */
        class FormePremisseSymboliqueConstante : public FormeAbstraitePremisse
        {

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] nomFait
                 * Le @ref nom_ du fait symbolique dans la comparaison.
                 * @param[in] comparateur
                 * L'opérateur (@ref signe_) de comparaison pour tester l'expression symbolique.
                 * @param[in] valeur
                 * La @ref valeur_ à tester sur celle du fait symbolique.
                 * */
                FormePremisseSymboliqueConstante( const std::string & nomFait,
                        FormeAbstraitePremisse::OperateurComparaisonString comparateur,
                        const std::string & valeur );

                /**
                 * Méthode de visite.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui va évaluer la prémisse,
                 * de façon nomFait signe valeur.
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
                bool test( const std::string & partieGauche, const std::string & partieDroite ) const;

                /**
                 * Accesseur
                 *
                 * @return La @ref valeur_ de l'expression.
                 * */
                const std::string & lireValeur() const;

            protected:

                /**
                 * Le signe de comparaison
                 * */
                const OperateurComparaisonString signe_;

                /**
                 * La valeur à laquelle on compare la prémisse symbolique.
                 * */
                const std::string valeur_;

        };

    }
}

#endif
