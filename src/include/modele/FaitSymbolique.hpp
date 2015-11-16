/**
 * @file FaitSymbolique.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier FaitSymbolique.cpp.
 * Définit la classe concrète FaitSymbolique.
 * */

#ifndef faitsymbolique_hpp
#define faitsymbolique_hpp

#include <cstdlib>

#include "FaitAbstrait.hpp"


namespace sysexp
{

    namespace modele
    {

        /**
         * @brief Représente un fait symbolique. Sa valeur ne peut pas être modifiée.
         *
         * Déclaration de la classe concrète FaitSymbolique.
         * Cette classe permet de représenter un fait symbolique et sa valeur.
         * */
        class FaitSymbolique : public FaitAbstrait
        {

            public:

                /**
                 * @typedef PtrFaitSymbolique
                 *
                 * Nom facile pour un shared_ptr de FaitSymbolique.
                 * */
                typedef std::shared_ptr< FaitSymbolique > PtrFaitSymbolique;

            public:

                /**
                 * Constructeur logique du fait symbolique.
                 *
                 * @param[in] nom
                 * Le @ref nom_ du fait symbolique.
                 * @param[in] valeur
                 * La @ref valeur_ du fait symbolique.
                 * */
                FaitSymbolique( const std::string & nom, const std::string & valeur );

                /**
                 * Accesseur.
                 *
                 * @return La @ref valeur_ du fait symbolique.
                 * */
                const std::string & lireValeur() const;

            public:

                FaitSymbolique( const FaitSymbolique & autre ) = delete;

                FaitSymbolique & operator=( const FaitSymbolique & autre ) = delete;

            protected:

                /**
                 * La valeur de notre fait symbolique, une chaine de caractère.
                 * La valeur d'un fait n'est pas censée changer.
                 * */
                const std::string valeur_;

        };
    }
}

#endif
