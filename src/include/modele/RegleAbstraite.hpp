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
                RegleAbstraite( const unsigned int & numeroRegle, const FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion & conclusion );

                /**
                 * Ajoute un successeur à la règle actuelle.
                 *
                 * @param[in] successeur
                 * La règle qui succède à la règle actuelle.
                 * */
                void ajouterSuccesseur( const PtrRegleAbstraite & successeur );

                /**
                 * Accesseur
                 *
                 * @return La règle @ref successeur_.
                 * */
                const RegleAbstraite::PtrRegleAbstraite & lireSuccesseur() const;

                /**
                 * @return La règle possède un successeur.
                 * */
                bool possedeSuccesseur() const;

                /**
                 * Méthode pour accepter un visiteur.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui vas évaluer la règle abstraite.
                 * @see VisiteurFormeAbstrait
                 * */
                virtual bool declencher( const BaseFait::PtrBaseFait & base ) = 0;

                /**
                 * @return La règle à été déclenchée.
                 * */
                bool estDeclenchee() const;

                /**
                 * Parcours la base de règle.
                 *
                 * @param[in, out] base
                 * La base de fait utilisé pour évaluer les règles.
                 *
                 * @return Une règle au moins à été déclenchée.
                 * */
                virtual bool iter( const BaseFait::PtrBaseFait & base ) = 0;

            public:

                /**
                * Destructeur de la RegleAbstraite.
                * */
                virtual ~RegleAbstraite() = default;

            protected:

                /**
                 * Le numéro de la règle dans la base de règle.
                 * Pour signaler facilement à l'utilisateur le numéro de la règle
                 * qui a causé une exception.
                 * */
                const unsigned int numeroRegle_;

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
