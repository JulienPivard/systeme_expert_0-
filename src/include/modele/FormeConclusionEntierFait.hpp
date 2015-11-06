/**
 * @file FormeConclusionEntierFait.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier FormeConclusionEntierFait.cpp.
 * Définit la classe abstraite FormeConclusionEntierFait.
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
        *
        * Déclaration de la classe FormeConclusionEntierFait.
        * */
        class FormeConclusionEntierFait
        {

            public:

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
                void accept( const std::shared_ptr< VisiteurFormeAbstrait > & visiteur );

        };

    }
}

#endif
