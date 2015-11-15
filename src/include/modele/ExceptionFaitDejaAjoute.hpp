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

#include <stdexcept>

/**
 * @namespace sysexp
 * // namespace global de l'application.
 * */
namespace sysexp
{
    /**
     * namespace sysexp::modele
     * // namespace modele de l'application.
     * */
    namespace modele
    {

        /**
         * @class ExceptionFaitDejaAjoute ExceptionFaitDejaAjoute.hpp
         * @brief On a tenté de modifier un fait déjà ajouté à la base de faits.
         *
         * Déclaration de l'exception pour signaler qu'un fait à déjà été ajouté à la base de faits.
         * */
        class ExceptionFaitDejaAjoute : public std::runtime_error
        {

            public:

                /**
                 * Le fait existe déjà dans la base de faits.
                 * */
                ExceptionFaitDejaAjoute():
                    std::runtime_error( "Erreur ! Le fait existe déjà. La base de règle est incohérente." )
                { }
        };

    }
}

#endif
