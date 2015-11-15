/**
 * @file FormePremisseBoolTrue.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
 *
 * Header pour le fichier FormePremisseBoolTrue.cpp.
 * Définit la classe concrète FormePremisseBoolTrue.
 * */


#ifndef formepremissebooltrue_hpp
#define formepremissebooltrue_hpp

#include "FormeAbstraitePremisse.hpp"


namespace sysexp
{
    
    namespace modele
    {

        /**
         * @brief Représente une prémisse vraie.
         *
         * Déclaration de la classe FormePremisseBoolTrue.
         * */
        class FormePremisseBoolTrue : public FormeAbstraitePremisse
        {

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] nom
                 * Le @ref nom_ du fait booléen vrai.
                 * */
                FormePremisseBoolTrue( const std::string & nom );

                /**
                 * Méthode de visite.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui va évaluer la prémisse booléenne.
                 * @see VisiteurFormeAbstrait
                 * */
                void accept( const PtrVisiteurFormeAbstrait & visiteur );

        };

    }
}

#endif
