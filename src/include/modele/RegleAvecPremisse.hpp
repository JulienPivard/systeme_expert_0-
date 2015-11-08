/**
 * @file RegleAvecPremisse.hpp
 * @brief header.
 * @author PIVARD Julien
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
         * @class RegleAvecPremisse RegleAvecPremisse.hpp
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

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] conclusion
                 * La conclusion de la règle.
                 * @param[in] premisse
                 * La premisse qui sert d'hypothèse, d'autres peuvent être ajouté avec @ref ajouterPremisse.
                 * */
                RegleAvecPremisse( const FormeAbstraitePremisse::PtrFormeAbstraitePremisse & premisse, const FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion & conclusion );

                /**
                 * Méthode pour accepter le visiteur.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui vas évaluer la règle sans conclusion.
                 * */
                void accept( const VisiteurFormeAbstrait::PtrVisiteurFormeAbstrait & visiteur );

                /**
                 * Méthode pour ajouter une prémisse.
                 * Le liens logique entre les prémisses est l'opérateur logique and.
                 *
                 * @param[in] premisse
                 * La prémisse à ajouter aux hypothèses de la règle.
                 * */
                void ajouterPremisse( const FormeAbstraitePremisse::PtrFormeAbstraitePremisse & premisse );

            protected:

                /**
                 * La liste des prémisses.
                 * Le liens logique entre les prémisses est le and.
                 * */
                Premisses premisses_;

        };

    }
}

#endif
