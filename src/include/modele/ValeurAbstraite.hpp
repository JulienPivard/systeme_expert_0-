/**
 * @file ValeurAbstraite.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier ValeurAbstraite.cpp.
 * Définit la classe abstraite ValeurAbstraite.
 * */

#ifndef valeurabstraite_hpp
#define valeurabstraite_hpp

#include <memory>

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
         * @class ValeurAbstraite ValeurAbstraite.hpp
         * @brief Le squelette d'une expression de valeur entière.
         *
         * Déclaration de la classe abstraite Valeur.
         * */
        class ValeurAbstraite
        {

            public:

                /**
                 * @typedef PtrValeur
                 *
                 * La valeur stocké sous forme de shared_ptr.
                 * */
                typedef std::shared_ptr< ValeurAbstraite > PtrValeur;

            public:

                /**
                 * Permet d'évaluer la valeur.
                 *
                 * @param[in] baseFait
                 * La base de fait à utiliser pour évaluer les expressions.
                 * @return La valeur.
                 * */
                virtual long int interpret( const BaseFait & baseFait ) const = 0;

                /**
                 * Destructeur virtuel.
                 * */
                virtual ~ValeurAbstraite() = default;

            protected:

        };

    }
}

#endif
