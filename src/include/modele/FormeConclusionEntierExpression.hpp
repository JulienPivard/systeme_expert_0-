/**
 * @file FormeConclusionEntierExpression.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier FormeConclusionEntierExpression.cpp.
 * Définit la classe concrète FormeConclusionEntierExpression.
 * */


#ifndef formeconclusionentierexpression_hpp
#define formeconclusionentierexpression_hpp

#include <string>

#include "FormeAbstraiteConclusion.hpp"
#include "ValeurAbstraite.hpp"
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
            * @class FormeConclusionEntierExpression FormeConclusionEntierExpression.hpp
            * @brief Représente une conclusion entière avec une expression mathématique.
            *
            * Déclaration de la classe FormeConclusionEntierExpression.
            * */
        class FormeConclusionEntierExpression : public FormeAbstraiteConclusion
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
                 * @param[in] valeur
                 * La valeur de l'expression entière.
                 * */
                FormeConclusionEntierExpression( const std::string & nom, const ValeurAbstraite::PtrValeur & valeur );

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
                 * @return La @ref valeur_ de la forme entière.
                 * */
                long int lireValeur( const BaseFait::PtrBaseFait & baseFait ) const;

            protected:

                /**
                 * La valeur qui vas être assignée sous forme d'une expression.
                 * */
                const ValeurAbstraite::PtrValeur valeur_;

        };

    }
}

#endif
