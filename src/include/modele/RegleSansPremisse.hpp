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
                 * @param[in] conclusion
                 * La conclusion de la règle.
                 * */
                RegleSansPremisse( const unsigned int & numeroRegle, const FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion & conclusion );

                /**
                 * Méthode pour accepter le visiteur.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui vas évaluer la règle sans conclusion.
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
