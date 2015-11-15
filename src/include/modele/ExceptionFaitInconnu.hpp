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

#include <stdexcept>

/**
 * @namespace sysexp
 * // namespace global de l'application.
 * */
namespace sysexp
{
    /**
     * @namespace sysexp::modele
     * // namespace modele de l'application.
     * */
    namespace modele
    {

        /**
        * @class ExceptionFaitInconnu ExceptionFaitInconnu.hpp
        * @brief Le fait demandé n'a pas pu être trouvé dans la base de faits.
        *
        * Déclaration de l'exception pour les faits non trouvés.
        * */
        class ExceptionFaitInconnu : public std::runtime_error
        {
            public:

                /**
                 * Le fait que l'on cherchait n'existe pas dans la base de faits.
                 * */
                ExceptionFaitInconnu():
                    std::runtime_error( "Erreur ! Le fait n'existe pas dans la base." )
                {}

        };

    }
}

#endif
