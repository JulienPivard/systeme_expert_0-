/**
 * @file FaitBool.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier FaitBool.cpp.
 * Définit la classe FaitBool.
 * */


#ifndef faitbool_hpp
#define faitbool_hpp

#include "Fait.hpp"

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
         * @class FaitBool FaitBool.hpp
         *
         * Déclaration de la classe concrète FaitBool.
         * Cette classe permet de représenter un fait booleen et sa valeur.
         * */
        class FaitBool : public Fait
        {

            public:
                /**
                 * @param[in] nom
                 * Le @ref nom_ du Fait booléen
                 * @param[in] valeur
                 * La @ref valeur_ du fait booléen.
                 * */
                FaitBool( const std::string & nom, const bool & valeur );

                /**
                 * @return La valeur du fait booléen.
                 * */
                bool lireValeur() const;

            protected:
                /**
                 * La valeur de notre fait booléen, soit true soit false.
                 * */
                const bool valeur_;

        };
    }
}

#endif

/*Pivard Julien*/
