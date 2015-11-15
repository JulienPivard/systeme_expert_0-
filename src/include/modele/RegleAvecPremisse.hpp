/**
 * @file RegleAvecPremisse.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
 *
 * Header pour le fichier RegleAvecPremisse.cpp.
 * Définit la classe abstraite RegleAvecPremisse.
 * */


#ifndef regleavecpremisse_hpp
#define regleavecpremisse_hpp

#include <set>

#include "RegleAbstraite.hpp"
#include "FormeAbstraiteConclusion.hpp"
#include "FormeAbstraitePremisse.hpp"
#include "VisiteurForme.hpp"


namespace sysexp
{
    
    namespace modele
    {

        /**
         * @brief Représente une règle avec prémisses.
         *
         * Déclaration de la classe RegleAvecPremisse.
         * */
        class RegleAvecPremisse : public RegleAbstraite
        {

            public:

                /**
                 * @typedef Premisses
                 *
                 * Le shared pointer sur le set de premisses.
                 * */
                typedef std::set< FormeAbstraitePremisse::PtrFormeAbstraitePremisse > Premisses;

                /**
                 * @typedef Premisses
                 *
                 * Alias pour le shared pointer sur une règle avec prémisse.
                 * */
                 typedef std::shared_ptr<RegleAvecPremisse> PtrRegleAvecPremisse;

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] numeroRegle
                 * Le @ref numeroRegle_ de la règle.
                 * @param[in] conclusion
                 * La @ref conclusion_ de la règle à ajouter
                 * dans la base de faits une fois la règle vérifiée.
                 * @param[in] premisse
                 * La premisse qui sert d'hypothèse, d'autres peuvent être ajoutées avec @ref ajouterPremisse.
                 *
                 * @note N'utiliser traceExecution que pour le debogage ! Laissez le champ vide sinon.
                 * */
                RegleAvecPremisse( const unsigned int & numeroRegle,
                        const FormeAbstraitePremisse::PtrFormeAbstraitePremisse & premisse,
                        const FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion & conclusion );

                /**
                 * Méthode pour ajouter une prémisse.
                 * Le lien logique entre les prémisses est l'opérateur logique and.
                 *
                 * @param[in] premisse
                 * La prémisse à ajouter aux hypothèses de la règle.
                 * */
                void ajouterPremisse( const FormeAbstraitePremisse::PtrFormeAbstraitePremisse & premisse );

                /**
                 * Parcours la base de règle.
                 *
                 * @param[in, out] base
                 * La base de faits utilisée pour évaluer les règles.
                 *
                 * @return Une règle au moins à été déclenchée.
                 * */
                bool iter( const BaseFait::PtrBaseFait & base );

                /**
                 * Parcoure les prémisses @ref premisses_ pour vérifier les prémisses par rapport à la base de faits.
                 *
                 * @param[in] base
                 * La base de faits utilisée pour vérifier la validité des faits.
                 *
                 * @return Toutes les prémisses sont vérifiées.
                 * */
                bool verifierPremisses( const BaseFait::PtrBaseFait & base );

                /**
                 * Affiche les variable interne de la règle.
                 *
                 * @note À n'utiliser que pour le debogage.
                 * */
                void afficher() const;

            protected:

                /**
                 * La liste des prémisses.
                 * Le lien logique entre les prémisses est le and.
                 * */
                Premisses premisses_;

        };

    }
}

#endif
