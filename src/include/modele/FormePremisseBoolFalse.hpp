/**
 * @file FormePremisseBoolFalse.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier FormePremisseBoolFalse.cpp.
 * Définit la classe concrète FormePremisseBoolFalse.
 * */

#ifndef formepremisseboolfalse_hpp
#define formepremisseboolfalse_hpp

#include "FormeAbstraitePremisse.hpp"

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
         * @class FormePremisseBoolFalse FormePremisseBoolFalse.hpp
         * @brief Représente un fait booléen faux.
         *
         * Déclaration de la classe FormePremisseBoolFalse.
         * */
        class FormePremisseBoolFalse : public FormeAbstraitePremisse
        {

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] nom
                 * Le @ref nom_ de la prémisse booléenne fausse.
                 * */
                FormePremisseBoolFalse( const std::string & nom );

                /**
                 * Méthode de visite.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui vas évaluer le prémisse booléen.
                 * @see VisiteurFormeAbstrait
                 * */
                void accept( const PtrVisiteurFormeAbstrait & visiteur );

        };

    }
}

#endif
