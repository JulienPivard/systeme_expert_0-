/**
 * @file FormeConclusionSymboliqueConstante.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier FormeConclusionSymboliqueConstante.cpp.
 * Définit la classe concrète FormeConclusionSymboliqueConstante.
 * */


#ifndef formeconclusionsymboliqueconstante_hpp
#define formeconclusionsymboliqueconstante_hpp

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
         * @class FormeConclusionSymboliqueConstante FormeConclusionSymboliqueConstante.hpp
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
                 * */
                typedef std::shared_ptr< VisiteurFormeAbstrait > PtrVisiteurFormeAbstrait;

                /**
                 * Constructeur logique
                 *
                 * @param[in] nom
                 * Le nom de la conclusion symbolique.
                 * @param[in] valeur
                 * La valeur qui vas être assigné au fait.
                 * */
                FormeConclusionSymboliqueConstante( const std::string & nom, const std::string & valeur );

                /**
                 * Méthode de visite.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui vas évaluer la conclusion symbolique.
                 * */
                void accept( const PtrVisiteurFormeAbstrait & visiteur );

                /**
                 * Accesseur
                 *
                 * @return La @ref valeur_ de la forme symbolique.
                 * */
                const std::string & lireValeur() const;

            protected:

                /**
                 * La valeur constante qui vas être assigné à la valeur.
                 * */
                const std::string valeur_;

        };

    }
}

#endif
