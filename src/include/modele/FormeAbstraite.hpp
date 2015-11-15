/**
 * @file FormeAbstraite.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier FormeAbstraite.cpp.
 * Définit la classe abstraite FormeAbstraite.
 * */


#ifndef formeabstraite_hpp
#define formeabstraite_hpp

#include <string>
#include <memory>
#include "VisiteurFormeAbstrait.hpp"

/**
 * @namespace sysexp
 * // namespace global de l'application.
 * */
namespace sysexp
{
    /**
     * @namespace sysexp::modele
     * // namespace modele de l'application.
     * */
    namespace modele
    {

        /**
         * @class FormeAbstraite FormeAbstraite.hpp
         * @brief Squelette de représentation d'une prémisse ou d'un conclusion.
         *
         * Déclaration de la classe abstraite FormeAbstraite.
         * */
        class FormeAbstraite
        {

            public:

                /**
                 * @typedef PtrVisiteurFormeAbstrait
                 *
                 * Un alias pour simplifier l'utilisation d'un shared pointeur de VisiteurFormeAbstrait
                 * */
                typedef std::shared_ptr< VisiteurFormeAbstrait > PtrVisiteurFormeAbstrait;

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] nom
                 * Le @ref nom_ de la FormeAbstraite.
                 * */
                FormeAbstraite( const std::string & nom );

                /**
                 * Méthode de visite.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui vas évaluer la FormeAbstraite.
                 * */
                virtual void accept( const PtrVisiteurFormeAbstrait & visiteur ) = 0;

                /**
                 * Accesseur
                 *
                 * @return Le @ref nom_ de la forme.
                 * */
                const std::string & lireNom() const;

                /**
                 * Le destructeur rendu virtuel.
                 * */
                virtual ~FormeAbstraite() = default;

            protected:

                /**
                 * Le nom de la FormeAbstraite.
                 * */
                const std::string nom_;

        };

    }
}

#endif
