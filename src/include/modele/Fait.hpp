/**
 * @file Fait.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier Fait.cpp.
 * Définit la classe Fait.
 * */

#ifndef fait_hpp
#define fait_hpp

#include <string>

/**
 * @namespace sysexp
 * */
namespace sysexp
{
    /**
    * @namespace modele
    * */
    namespace modele
    {
        /**
         * @class Fait Fait.hpp
         *
         * Déclaration de la classe abstraite Fait.
         * */
        class Fait
        {

            public:
                /**
                 * Constructeur logique
                 *
                 * @param[in] nom - Le @ref nom_ du fait.
                 * */
                Fait( const std::string & nom );
                Fait( const Fait & autre ) = delete;
                Fait & operator= ( const Fait & autre ) = delete;

                /**
                 * Accesseur
                 *
                 * @return Le @ref nom_ du fait.
                 * */
                const std::string & lireNom() const;

                /**
                 * La méthode virtuel destructeur.
                 * */
                virtual ~Fait() = default;

            protected:
                /**
                 * Le nom qu'on a donné au fait.
                 * */
                const std::string nom_;

        };
    }
}

#endif

/*Pivard Julien*/
