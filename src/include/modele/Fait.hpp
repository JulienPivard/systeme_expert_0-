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
 * @namespace
 * */
namespace sysexp
{
    /**
    * @namespace
    * */
    namespace modele
    {
        /**
         * @class Fait Fait.hpp
         * La classe abstraite des faits.
         * */
        class Fait
        {

            public:
                Fait( const std::string & nom );
                Fait & operator= ( const Fait & autre ) = delete;
                const std::string & lireNom() const;
                virtual ~Fait() = default;

            protected:
                const std::string nom_;

        };
    }
}

#endif

/*Pivard Julien*/
