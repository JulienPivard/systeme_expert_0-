/**
 * @file FormeConclusionSymboliqueConstante.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier FormeConclusionSymboliqueConstante.cpp.
 * Définit la classe concrète FormeConclusionSymboliqueConstante.
 * */


#ifndef formeconclusionsymboliqueconstante_hpp
#define formeconclusionsymboliqueconstante_hpp

#include <string>

#include "FormeAbstraiteConclusion.hpp"


namespace sysexp
{

    namespace modele
    {

        /**
         * @brief Représente une conclusion symbolique de valeur constante.
         *
         * Déclaration de la classe FormeConclusionSymboliqueConstante.
         * */
        class FormeConclusionSymboliqueConstante : public FormeAbstraiteConclusion
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
                 * Le @ref nom_ de la conclusion symbolique.
                 * @param[in] valeur
                 * La @ref valeur_ qui va être assignée au fait.
                 * */
                FormeConclusionSymboliqueConstante( const std::string & nom, const std::string & valeur );

                /**
                 * Méthode de visite.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui va évaluer la conclusion symbolique.
                 * @see VisiteurFormeAbstrait
                 * */
                void accept( const PtrVisiteurFormeAbstrait & visiteur );

                /**
                 * Accesseur
                 *
                 * @return La @ref valeur_ de la forme symbolique.
                 * */
                const std::string & lireValeur() const;

            public:

                FormeConclusionSymboliqueConstante( const FormeConclusionSymboliqueConstante & autre ) = delete;

                FormeConclusionSymboliqueConstante & operator=( const FormeConclusionSymboliqueConstante & autre ) = delete;

            protected:

                /**
                 * La valeur constante qui va être assignée à la valeur.
                 * */
                const std::string valeur_;

        };

    }
}

#endif
