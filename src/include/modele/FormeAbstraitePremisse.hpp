/**
 * @file FormeAbstraitePremisse.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier FormeAbstraitePremisse.cpp.
 * Définit la classe abstraite FormeAbstraitePremisse.
 * */


#ifndef formeabstraitepremisse_hpp
#define formeabstraitepremisse_hpp

#include <memory>
#include <functional>

#include "FormeAbstraite.hpp"


namespace sysexp
{

    namespace modele
    {

        /**
         * @brief Le squelette de représentation d'une prémisse.
         *
         * Déclaration de la classe FormeAbstraitePremisse.
         * */
        class FormeAbstraitePremisse : public FormeAbstraite
        {

            public:

                /**
                 * @typedef PtrFormeAbstraitePremisse
                 *
                 * Alias pour faciliter l'utilisation d'un shared_ptr de FormeAbstraitePremisse.
                 * */
                typedef std::shared_ptr< FormeAbstraitePremisse > PtrFormeAbstraitePremisse;

                /**
                 * @typedef OperateurComparaisonEntier
                 *
                 * Le prototype de l'opérateur de comparaison entre long entier,
                 * avec les comparateurs de la librairie standard.
                 * */
                typedef std::function< bool( const long int & gauche, const long int & droite ) >OperateurComparaisonEntier;

                /**
                 * @typedef OperateurComparaisonString
                 *
                 * Le prototype de l'opérateur de comparaison entre string,
                 * avec les comparateurs de la librairie standard.
                 * */
                typedef std::function< bool( const std::string & gauche, const std::string & droite ) >OperateurComparaisonString;

            public:

                /**
                 * Constructeur logique.
                 *
                 * @param[in] nom
                 * Le @ref nom_ du fait avec lequel sera fait la comparaison.
                 * */
                FormeAbstraitePremisse( const std::string & nom );

                /**
                 * Destructeur rendu virtuel.
                 * */
                virtual ~FormeAbstraitePremisse() = default;

            public:

                FormeAbstraitePremisse( const FormeAbstraitePremisse & autre ) = delete;

                FormeAbstraitePremisse & operator=( const FormeAbstraitePremisse & autre ) = delete;

        };

    }

}

#endif
