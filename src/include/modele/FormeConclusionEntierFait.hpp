/**
 * @file FormeConclusionEntierFait.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier FormeConclusionEntierFait.cpp.
 * Définit la classe concrète FormeConclusionEntierFait.
 * */


#ifndef formeconclusionentierefait_hpp
#define formeconclusionentierefait_hpp

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
        * @class FormeConclusionEntierFait FormeConclusionEntierFait.hpp
        * @brief Représente une conclusion entière dont la valeur dépend de celle d'un fait entier.
        *
        * Déclaration de la classe FormeConclusionEntierFait.
        * */
        class FormeConclusionEntierFait : public FormeAbstraiteConclusion
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
                 * Le nom de la conclusion entière.
                 * @param[in] nomFait
                 * Le nom du fait entier dont on veut assigner la valeur.
                 * */
                FormeConclusionEntierFait( const std::string & nom, const std::string & nomFait );

                /**
                 * Méthode de visite.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui vas évaluer la conclusion entière.
                 * */
                void accept( const PtrVisiteurFormeAbstrait & visiteur );

                /**
                 * Accesseur
                 *
                 * @return La @ref nomFait_ de la forme entière.
                 * */
                const std::string & lireNomFait() const;

            protected:

                /**
                 * Le nom du fait dont on veut assigner la valeur.
                 * */
                const std::string nomFait_;

        };

    }
}

#endif
