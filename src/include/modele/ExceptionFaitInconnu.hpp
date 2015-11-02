/**
 * @file ExceptionFaitInconnu.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier ExceptionFaitInconnu.cpp.
 * Définit la classe d'exception concrète ExceptionFaitInconnu.
 * */


#ifndef exceptionfaitinconnu_hpp
#define exceptionfaitinconnu_hpp

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
        * @class ExceptionFaitInconnu ExceptionFaitInconnu.hpp
        *
        * Déclaration de l'exception pour les faits non trouvé.
        * */
        class ExceptionFaitInconnu : public std::runtime_error
        {
            public:

                /**
                 * Le fait que l'on chercher n'existe pas dans la base de fait.
                 * */
                ExceptionFaitInconnu():
                    std::runtime_error( "Erreur ! Le fait n'existe pas dans la base." )
                {}

        };

    }
}

#endif
