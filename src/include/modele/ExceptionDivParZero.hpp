/**
 * @file ExceptionDivParZero.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier ExceptionDivParZero.cpp.
 * Définit la classe d'exception concrète ExceptionDivParZero.
 * */


#ifndef exceptiondivparzero_hpp
#define exceptiondivparzero_hpp

#include <stdexcept>

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
         * @class ExceptionDivParZero ExceptionDivParZero.hpp
         *
         * Déclaration de l'exception pour la division par zéro.
         * */
        class ExceptionDivParZero : public std::runtime_error
        {

            public:

                /**
                 * Tentative de division par zéro.
                 * */
                ExceptionDivParZero():
                    std::runtime_error( "Erreur ! Tentative de division par zéro." )
                { }

        };

    }
}

#endif
