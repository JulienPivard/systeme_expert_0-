/**
 * @file FormeConclusionEntierExpression.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier FormeConclusionEntierExpression.cpp.
 * Définit la classe abstraite FormeConclusionEntierExpression.
 * */


#ifndef formeconclusionentierexpression_hpp
#define formeconclusionentierexpression_hpp

#include <string>

#include "FormeAbstraiteConclusion.hpp"
#include "ValeurAbstraite.hpp"

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
            * @class FormeConclusionEntierExpression FormeConclusionEntierExpression.hpp
            *
            * Déclaration de la classe FormeConclusionEntierExpression.
            * */
        class FormeConclusionEntierExpression : public FormeAbstraiteConclusion
        {

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] nom
                 * Le nom de la conclusion entière.
                 * @param[in] valeur
                 * La valeur de l'expression entière.
                 * */
                FormeConclusionEntierExpression( const std::string & nom, const ValeurAbstraite & valeur );

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
