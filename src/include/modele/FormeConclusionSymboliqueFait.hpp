/**
 * @file FormeConclusionSymboliqueFait.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier FormeConclusionSymboliqueFait.cpp.
 * Définit la classe abstraite FormeConclusionSymboliqueFait.
 * */


#ifndef formeconclusionsymboliquefait_hpp
#define formeconclusionsymboliquefait_hpp

#include <string>

#include "FormeAbstraiteConclusion.hpp"

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
         * @class FormeConclusionSymboliqueFait FormeConclusionSymboliqueFait.hpp
         *
         * Déclaration de la classe FormeConclusionSymboliqueFait.
         * */
        class FormeConclusionSymboliqueFait : public FormeAbstraiteConclusion
        {

            public:

                /**
                 * @typedef PtrVisiteurFormeAbstrait
                 *
                 * Un alias pour simplifier l'utilisation d'un shared pointeur de VisiteurFormeAbstrait
                 * */
                typedef std::shared_ptr< VisiteurFormeAbstrait > PtrVisiteurFormeAbstrait;

                /**
                 * Constructeur logique
                 *
                 * @param[in] nom
                 * Le nom de la conclusion symbolique.
                 * @param[in] nomFait
                 * Le nom du fait entier dont on veut assigner la valeur.
                 * */
                FormeConclusionSymboliqueFait( const std::string & nom, const std::string & nomFait );

                /**
                 * Méthode de visite.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui vas évaluer la conclusion symbolique.
                 * */
                void accept( const PtrVisiteurFormeAbstrait & visiteur );

                /**
                 * Accesseur
                 *
                 * @return La @ref nomFait_ de la forme symbolique.
                 * */
                const std::string & lireNomFait() const;

            protected:

                /**
                 * Le nom du fait dont on veut assigner la valeur.
                 * */
                const std::string nomFait_;

        };

    }
}

#endif
