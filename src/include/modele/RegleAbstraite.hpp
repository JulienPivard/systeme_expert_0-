/**
 * @file RegleAbstraite.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier RegleAbstraite.cpp.
 * Définit la classe abstraite RegleAbstraite.
 * */


#ifndef regleabstraite_hpp
#define regleabstraite_hpp

#include <cstdlib>
#include <memory>

#include "FormeAbstraiteConclusion.hpp"
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
        * @class RegleAbstraite RegleAbstraite.hpp
        * @brief Le squelette d'une règle avec ou sans prémisse.
        *
        * Déclaration de la classe RegleAbstraite.
        * */
        class RegleAbstraite
        {

            public:

                /**
                 * @typedef PtrRegleAbstraite
                 *
                 * Un alias pour simplifier l'utilisation d'un shared_ptr sur RegleAbstraite.
                 * */
                typedef std::shared_ptr< RegleAbstraite > PtrRegleAbstraite;

            public:

                /**
                 * Constructeur logique.
                 *
                 * @param[in] conclusion
                 * La conclusion de la règle.
                 * @see FormeAbstraiteConclusion
                 * */
                RegleAbstraite( const FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion & conclusion );

                /**
                 * Ajoute un successeur à la règle actuelle.
                 *
                 * @param[in] successeur
                 * La règle qui succède à la règle actuelle.
                 * */
                void ajouterSuccesseur( const PtrRegleAbstraite & successeur );

                /**
                 * Méthode pour accepter un visiteur.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui vas évaluer la règle abstraite.
                 * @see VisiteurFormeAbstrait
                 * */
                virtual void accept( const VisiteurFormeAbstrait::PtrVisiteurFormeAbstrait & visiteur ) = 0;

                /**
                 * @return La règle à été déclenchée.
                 * */
                bool estDeclenchee() const;

                /**
                 * @return La règle possède un successeur.
                 * */
                bool possedeSuccesseur() const;

            public:

                /**
                * Destructeur de la RegleAbstraite.
                * */
                virtual ~RegleAbstraite() = default;

            protected:

                /**
                 * La conclusion de la règle.
                 * @see FormeAbstraiteConclusion
                 * */
                const FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion_;

                /**
                 * La règle suivante.
                 * */
                PtrRegleAbstraite successeur_;

                /**
                 * La règle à été déclenchée.
                 * */
                bool declenchee_;

        };

    }
}

#endif
