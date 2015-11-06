/**
 * @file FormeConclusionBoolFalse.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier FormeConclusionBoolFalse.cpp.
 * Définit la classe abstraite FormeConclusionBoolFalse.
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
         *
         * Déclaration de la classe FormeConclusionBoolFalse.
         * */
        class FormeConclusionBoolFalse : public FormeAbstraiteConclusion
        {

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] nom
                 * Le nom de la conclusion booléenne.
                 * */
                FormeConclusionBoolFalse( const std::string & nom );

                /**
                 * Méthode de visite.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui vas évaluer la conclusion booléenne.
                 * */
                void accept( const std::shared_ptr< VisiteurFormeAbstrait > & visiteur );

        };

    }
}

#endif
