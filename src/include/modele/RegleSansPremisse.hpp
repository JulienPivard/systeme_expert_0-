/**
 * @file RegleSansPremisse.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier RegleSansPremisse.cpp.
 * Définit la classe concrète RegleSansPremisse.
 * */


#ifndef reglesansconclusion_hpp
#define reglesansconclusion_hpp

#include <exception>

#include "RegleAbstraite.hpp"
#include "FormeAbstraiteConclusion.hpp"
#include "VisiteurForme.hpp"

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
         * @class RegleSansPremisse RegleSansPremisse.hpp
         * @brief Représente une règle sans prémisse.
         *
         * Déclaration de la classe RegleSansPremisse.
         * */
        class RegleSansPremisse : public RegleAbstraite
        {

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] numeroRegle
                 * Le numéro de la règle dans la base de connaissance,
                 * à l'intention de l'utilisateur en cas d'erreur d'exécution.
                 * @param[in] conclusion
                 * La conclusion de la règle.
                 * */
                RegleSansPremisse( const unsigned int & numeroRegle, const FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion & conclusion );

                /**
                 * Méthode pour accepter le visiteur.
                 *
                 * @param[in, out] base
                 * La base à partir de laquelle on évalue le déclenchement des règles,
                 * et à laquelle on vas ajouter la conclusion.
                 *
                 * @return La règle à été déclenchée.
                 * @see BaseFait
                 * */
                bool declencher( const BaseFait::PtrBaseFait & base );

                /**
                 * Parcours la base de règle.
                 *
                 * @param[in, out] base
                 * La base de fait utilisé pour évaluer les règles.
                 *
                 * @return Une règle au moins à été déclenchée.
                 * */
                bool iter( const BaseFait::PtrBaseFait & base );

        };

    }
}

#endif
