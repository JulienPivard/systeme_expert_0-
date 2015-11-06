/**
 * @file VisiteurForme.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier VisiteurForme.cpp.
 * Définit la classe abstraite VisiteurForme.
 * */


#ifndef visiteurforme_hpp
#define visiteurforme_hpp

#include "VisiteurFormeAbstrait.hpp"
#include "BaseFait.hpp"

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
        * @class VisiteurForme VisiteurForme.hpp
        *
        * Déclaration de la classe VisiteurForme.
        * */
        class VisiteurForme : public VisiteurFormeAbstrait
        {

            public:

                /**
                 * @typedef PtrVisiteurForme
                 *
                 * Un alias pour se faciliter l'utilisation de shared pointer de VisiteurForme.
                 * */
                typedef std::shared_ptr< VisiteurForme > PtrVisiteurForme;

            public:

                /**
                * Constructeur logique
                *
                * @param[in] baseFait
                * La base de fait que l'on va remplir.
                * */
                VisiteurForme( const BaseFait::PtrBaseFait & baseFait );

                /**
                 * Visite la règle passé en argument.
                 * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                 *
                 * @param[in,out] conclusion
                 * La conclusion que l'on veut visiter.
                 * @see FormeConclusionBoolTrue
                 * */
                void visiterConclusionBool( const FormeConclusionBoolTrue * conclusion );

        };

    }
}

#endif
