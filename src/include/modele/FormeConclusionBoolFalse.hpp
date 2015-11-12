/**
 * @file FormeConclusionBoolFalse.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier FormeConclusionBoolFalse.cpp.
 * Définit la classe concrète FormeConclusionBoolFalse.
 * */


#ifndef formeconclusionboolfalse_hpp
#define formeconclusionboolfalse_hpp

#include <string>

#include "FormeAbstraiteConclusion.hpp"

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
         * @class FormeConclusionBoolFalse FormeConclusionBoolFalse.hpp
         * @brief Représente une conclusion booléenne fausse.
         *
         * Déclaration de la classe FormeConclusionBoolFalse.
         * */
        class FormeConclusionBoolFalse : public FormeAbstraiteConclusion
        {

            public:

                /**
                 * @typedef PtrVisiteurFormeAbstrait
                 *
                 * Un alias pour simplifier l'utilisation d'un shared pointeur de VisiteurFormeAbstrait
                 * @see VisiteurFormeAbstrait
                 * */
                typedef std::shared_ptr< VisiteurFormeAbstrait > PtrVisiteurFormeAbstrait;

                /**
                 * Constructeur logique
                 *
                 * @param[in] nom
                 * Le @ref nom_ de la conclusion booléenne.
                 * */
                FormeConclusionBoolFalse( const std::string & nom );

                /**
                 * Méthode de visite.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui vas évaluer la conclusion booléenne.
                 * @see VisiteurFormeAbstrait
                 * */
                void accept( const PtrVisiteurFormeAbstrait & visiteur );

        };

    }
}

#endif
