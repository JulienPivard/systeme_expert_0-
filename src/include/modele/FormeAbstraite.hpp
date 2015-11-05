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

        class VisiteurFormesAbstrait;

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
                virtual void accept( const VisiteurFormesAbstrait & visiteur ) = 0;

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
