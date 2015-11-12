/**
 * @file FormePremisseSymboliqueFait.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier FormePremisseSymboliqueFait.cpp.
 * Définit la classe concrète FormePremisseSymboliqueFait.
 * */


#ifndef formepremissesymboliquefait_hpp
#define formepremissesymboliquefait_hpp

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
         * @class FormePremisseSymboliqueFait FormePremisseSymboliqueFait.hpp
         * @brief Représente la comparaison de la valeur d'un fait symbolique avec celle d'un autre fait symbolique.
         *
         * Déclaration de la classe FormePremisseSymboliqueFait.
         * */
        class FormePremisseSymboliqueFait : public FormeAbstraitePremisse
        {

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] nomFait
                 * Le nom du fait symbolique dans la comparaison.
                 * @param[in] comparateur
                 * L'opérateur de comparaison pour tester l'expression symbolique.
                 * @param[in] nomAutreFait
                 * L'autre fait
                 * */
                FormePremisseSymboliqueFait( const std::string & nomFait,
                        FormeAbstraitePremisse::OperateurComparaisonString comparateur,
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
                 * Permet de tester les valeurs selon l'opérateur de comparaison stocké.
                 *
                 * @param[in] partieGauche
                 * La partie gauche de la comparaison.
                 * @param[in] partieDroite
                 * La partie droite de la comparaison.
                 *
                 * @return Le signe de l'opération booléenne à effectuer.
                 * */
                bool test( const std::string & partieGauche, const std::string & partieDroite ) const;

                /**
                 * Accesseur
                 *
                 * @return La valeur de l'expression.
                 * */
                const std::string & lireNomAutreFait() const;

            protected:

                /**
                 * Le signe de comparaison
                 * */
                const OperateurComparaisonString signe_;

                /**
                 * Le nom de l'autre fait dans la comparaison.
                 * */
                const std::string nomAutreFait_;

        };

    }
}

#endif

