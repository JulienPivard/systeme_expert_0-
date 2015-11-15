/**
 * @file FormeConclusionBoolTrue.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier FormeConclusionBoolTrue.cpp.
 * Définit la classe concrète FormeConclusionBoolTrue.
 * */


#ifndef formeconclusionbooltrue_hpp
#define formeconclusionbooltrue_hpp

#include <string>

#include "FormeAbstraiteConclusion.hpp"

/**
 * @namespace sysexp
 * // namespace global de l'application.
 * */
namespace sysexp
{
    /**
     * @namespace sysexp::modele
     * // namespace modele de l'application.
     * */
    namespace modele
    {

        /**
         * @class FormeConclusionBoolTrue FormeConclusionBoolTrue.hpp
         * @brief Représente une conclusion booléenne vraie.
         *
         * Déclaration de la classe FormeConclusionBoolTrue.
         * */
        class FormeConclusionBoolTrue : public FormeAbstraiteConclusion
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
                FormeConclusionBoolTrue( const std::string & nom );

                /**
                 * Méthode de visite.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui va évaluer la conclusion booléenne.
                 * @see VisiteurFormeAbstrait
                 * */
                void accept( const PtrVisiteurFormeAbstrait & visiteur );

        };

    }
}

#endif
