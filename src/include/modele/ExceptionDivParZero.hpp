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

#include <exception>
#include <string>


namespace sysexp
{

    namespace modele
    {

        /**
         * @brief Une ValeurAbstraite à tenté une division par zéro.
         * Déclaration de l'exception pour la division par zéro.
         * */
        class ExceptionDivParZero : public std::exception
        {

            public:

                /**
                 * Tentative de division par zéro.
                 * @param[in] erreur
                 * L'explication de l'erreur généré.
                 * */
                ExceptionDivParZero( const std::string & erreur );

                /**
                 * @return Explicite l'exception.
                 * */
                const char* what() const throw() override;

            protected:

                /**
                 * Le texte de l'exception.
                 * */
                const std::string erreur_;

        };

    }

}

#endif
