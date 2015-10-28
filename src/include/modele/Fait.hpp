/**
 * @file Fait.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier Fait.cpp.
 * Définit la classe abstraite Fait.
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
    * @namespace sysexp::modele
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
                 * Le nom n'est pas censé changer je le met donc constant.
                 * */
                const std::string nom_;

        };
    }
}

#endif
