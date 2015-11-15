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
#include "VisiteurForme.hpp"


namespace sysexp
{
    /// paquetage contenant les composant logiciels relatifs au modele de données.
    namespace modele
    {

        /**
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
                 * @param[in] numeroRegle
                 * Le @ref numeroRegle_ de la règle dans la base de connaissance,
                 * à l'intention de l'utilisateur en cas d'erreur d'exécution.
                 * @param[in] conclusion
                 * La @ref conclusion_ de la règle.
                 *
                 * @note N'utiliser traceExecution que pour le debogage ! Laissez le champ vide sinon.
                 *
                 * @see FormeAbstraiteConclusion
                 * */
                RegleAbstraite( const unsigned int & numeroRegle,
                        const FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion & conclusion );

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
                 * @return La règle à été déclenchée.
                 * */
                bool estDeclenchee() const;

                /**
                 * Méthode pour accepter un visiteur.
                 *
                 * @param[in, out] base
                 * La base à partir de laquelle on évalue le déclenchement des règles,
                 * et à laquelle on va ajouter la conclusion.
                 *
                 * @return La règle à été déclenchée.
                 * @see BaseFait
                 * */
                bool declencher( const BaseFait::PtrBaseFait & base );

                /**
                 * Parcoure la base de règles.
                 *
                 * @param[in, out] base
                 * La base de faits utilisé pour évaluer les règles.
                 *
                 * @return Une règle au moins à été déclenchée.
                 * */
                bool iter( const BaseFait::PtrBaseFait & base );

                /**
                 * Vérifie que toutes les prémisses sont vérifiées par rapport à la base de faits.
                 *
                 * @param[in] base
                 * La base de faits utilisée pour vérifier les prémisses.
                 *
                 * @return Toutes les prémisses sont vérifiées.
                 * */
                virtual bool verifierPremisses( const BaseFait::PtrBaseFait & base ) = 0;

            public:

                /**
                * Destructeur de la RegleAbstraite.
                * */
                virtual ~RegleAbstraite() = default;

                /**
                 * Affiche les variable interne de la règle.
                 *
                 * @note À n'utiliser que pour le debogage.
                 * */
                void afficher() const;

            protected:

                /**
                 * Vérifie les flags d'erreur du visiteur.
                 *
                 * @param[in] visiteur
                 * Le visiteur qui a déclenché la conclusion ou les prémisses.
                 * @see VisiteurFormeAbstrait
                 *
                 * @throw ExceptionDivParZero
                 * Division par zéro rencontré impossible de continuer.
                 *
                 * @throw ExceptionFaitDejaAjoute
                 * On tente de modifier un fait déjà ajouté a la base de faits.
                 * Impossible de continuer.
                 * */
                void verifFlagErreurVisiteur( const VisiteurFormeAbstrait::PtrVisiteurFormeAbstrait & visiteur ) const;

            protected:

                /**
                 * Le numéro de la règle dans la base de règles.
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

                /**
                 * Permet l'affichage de l'état du visiteur,
                 * après à chaque visite d'un élément de la règle.
                 *
                 * @note À n'utiliser que à des fins de debogage,
                 * peut produire un affichage disgracieux.
                 * */
                bool traceExecution_;

        };

    }
}

#endif
