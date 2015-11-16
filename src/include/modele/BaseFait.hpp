/**
 * @file BaseFait.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy.
 *
 * Header pour le fichier BaseFait.cpp.
 * Définit la classe concrète BaseFait.
 * */


#ifndef basefait_hpp
#define basefait_hpp

#include <cstdlib>
#include <iostream>
#include <string>
#include <memory>
#include <map>

#include "FaitAbstrait.hpp"
#include "FaitEntier.hpp"
#include "FaitBool.hpp"
#include "FaitSymbolique.hpp"
#include "ExceptionFaitInconnu.hpp"
#include "ExceptionFaitDejaAjoute.hpp"
#include "ExceptionDivParZero.hpp"


namespace sysexp
{

    namespace modele
    {

        /**
        * @brief Permet de gérer les faits facilement et d'afficher la base de faits.
        * */
        class BaseFait
        {

            public:

                /**
                 * @typedef PtrBaseFait
                 *
                 * Le shared pointer vers la base de faits.
                 * */
                typedef std::shared_ptr< BaseFait > PtrBaseFait;

                /**
                 * @typedef Contenu
                 *
                 * Nom pour faciliter l'écriture et la manipulation de la variable @ref baseFait_
                 * */
                typedef std::map<std::string, FaitAbstrait::PtrFaitAbstrait> Contenu;

            public:

                /**
                 * Affiche le contenu de la base de faits sur la sortie standard.
                 * */
                void afficher() const;

                /**
                 * Test si un fait existe dans la base de faits.
                 *
                 * @param[in] nomFait
                 * Le nom du fait recherché
                 *
                 * @return Le fait à été trouvé. @see FaitAbstrait
                 * */
                bool appartient( const std::string & nomFait ) const;

                /**
                 * Trouve le fait grâce à son nom.
                 *
                 * @param[in] nomFait
                 * Le nom du fait recherché.
                 *
                 * @return Le fait trouvé. @see FaitAbstrait
                 *
                 * @throws ExceptionFaitInconnu
                 * Le fait demandé n'existe pas.
                 * */
                const FaitAbstrait::PtrFaitAbstrait & trouver( const std::string & nomFait ) const;

                /**
                 * Ajoute un fait à la base de faits.
                 *
                 * @param[in] fait
                 * Le fait à ajouter à la base de faits. @see FaitAbstrait
                 *
                 * @throws ExceptionFaitDejaAjoute
                 * Le fait existe déjà avec une autre valeur,
                 * la valeur ne peut pas être modifiée.
                 * */
                void ajouter( const FaitAbstrait::PtrFaitAbstrait & fait );

            public:

                BaseFait & operator=( const BaseFait & autre ) = delete;

            protected:

                /**
                * La liste de tout les faits. @see FaitAbstrait.
                * */
                Contenu baseFait_;

        };

    }

}

#endif
