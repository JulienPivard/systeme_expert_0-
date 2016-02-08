/**
 * @file ExceptionFaitInconnu.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
 *
 * Header pour le fichier ExceptionFaitInconnu.cpp.
 * Définit la classe d'exception concrète ExceptionFaitInconnu.
 * */


#ifndef exceptionfaitinconnu_hpp
#define exceptionfaitinconnu_hpp

#include <exception>
#include <string>


namespace sysexp
{

    namespace modele
    {

        /**
        * @brief Le fait demandé n'a pas pu être trouvé dans la base de faits.
        * Déclaration de l'exception pour les faits non trouvés.
        * */
        class ExceptionFaitInconnu : public std::exception
        {

            public:

                /**
                 * Le fait que l'on cherchait n'existe pas dans la base de faits.
                 * @param[in] erreur
                 * L'exception de l'erreur généré.
                 * */
                ExceptionFaitInconnu( const std::string & erreur );

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
