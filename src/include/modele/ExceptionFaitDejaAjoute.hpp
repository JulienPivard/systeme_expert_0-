/**
 * @file ExceptionFaitDejaAjoute.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
 *
 * Header pour le fichier ExceptionFaitDejaAjoute.cpp.
 * Définit la classe d'exception concrète ExceptionFaitDejaAjoute.
 * */


#ifndef exceptionfaitdejaajoute_hpp
#define exceptionfaitdejaajoute_hpp

#include <exception>
#include <string>


namespace sysexp
{

    namespace modele
    {

        /**
         * @brief On a tenté de modifier un fait déjà ajouté à la base de faits.
         * Déclaration de l'exception pour signaler qu'un fait à déjà été ajouté à la base de faits.
         * */
        class ExceptionFaitDejaAjoute : public std::exception
        {

            public:

                /**
                 * Le fait existe déjà dans la base de faits.
                 * @param[in] erreur
                 * L'explication de l'erreur généré.
                 * */
                ExceptionFaitDejaAjoute( const std::string & erreur );

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
