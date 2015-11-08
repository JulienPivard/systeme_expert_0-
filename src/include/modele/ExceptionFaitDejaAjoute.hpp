/**
 * @file ExceptionFaitDejaAjoute.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier ExceptionFaitDejaAjoute.cpp.
 * Définit la classe d'exception concrète ExceptionFaitDejaAjoute.
 * */


#ifndef exceptionfaitdejaajoute_hpp
#define exceptionfaitdejaajoute_hpp

#include <stdexcept>

/**
 * @namespace sysexp
 * */
namespace sysexp
{
    /**
     * namespace sysexp::modele
     * */
    namespace modele
    {

        /**
         * @class ExceptionFaitDejaAjoute ExceptionFaitDejaAjoute.hpp
         * @brief On a tenté de modifier un fait déjà ajouté à la base de fait.
         *
         * Déclaration de l'exception pour signaler qu'un fait à déjà été ajouté à la base de fait.
         * */
        class ExceptionFaitDejaAjoute : public std::runtime_error
        {

            public:

                /**
                 * Le fait existe déjà dans la base de fait.
                 * */
                ExceptionFaitDejaAjoute():
                    std::runtime_error( "Erreur ! Le fait existe déjà. La base de règle est incohérente." )
                { }
        };

    }
}

#endif
