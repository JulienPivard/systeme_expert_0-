/**
 * @file FormeAbstraite.hpp
 * @brief header.
 * @author PIVARD Julien
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
 * */
namespace sysexp
{
    /**
     * @namespace sysexp::modele
     * */
    namespace modele
    {

        /**
         * @class FormeAbstraite FormeAbstraite.hpp
         *
         * Déclaration de la classe abstraite FormeAbstraite.
         * */
        class FormeAbstraite
        {

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] nom
                 * Le nom de la FormeAbstraite. Voir @ref nom_
                 * */
                FormeAbstraite( const std::string & nom );

                /**
                 * Méthode de visite.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui vas évaluer la FormeAbstraite.
                 * */
                virtual void accept( const std::shared_ptr< VisiteurFormeAbstrait > & visiteur ) = 0;

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
