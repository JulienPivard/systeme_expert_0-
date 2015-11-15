/**
 * @file ExceptionDivParZero.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
 *
 * Header pour le fichier ExceptionDivParZero.cpp.
 * Définit la classe d'exception concrète ExceptionDivParZero.
 * */


#ifndef exceptiondivparzero_hpp
#define exceptiondivparzero_hpp

#include <stdexcept>


namespace sysexp
{
    
    namespace modele
    {

        /**
         * @brief Une ValeurAbstraite à tenté une division par zéro.
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
