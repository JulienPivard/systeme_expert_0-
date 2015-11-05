/**
 * @file BaseFait.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier BaseFait.cpp.
 * Définit la classe abstraite BaseFait.
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
        * @class BaseFait BaseFait.hpp
        *
        * Déclaration de la classe BaseFait.
        * Cette classe permet d'accéder aux faits.
        * */
        class BaseFait
        {

            public:

                /**
                 * @typedef PtrBaseFait
                 *
                 * Le shared pointer vers la base de fait.
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
                 * Affiche le contenu de la base de fait sur la sortie standard.
                 * */
                void afficher() const;

                /**
                 * Test si un fait existe dans la base de fait.
                 *
                 * @param[in] nomFait
                 * Le nom du fait recherché
                 * @return Le fait à été trouvé.
                 * */
                bool appartient( const std::string & nomFait ) const;

                /**
                 * Trouve le fait grâce à son nom.
                 *
                 * @param[in] nomFait
                 * Le nom du fait recherché.
                 * @throws ExceptionFaitInconnu
                 * Le fait demandé n'existe pas.
                 * @return Le fait trouvé. @see FaitAbstrait
                 * */
                const FaitAbstrait::PtrFaitAbstrait & trouver( const std::string & nomFait ) const;

                /**
                 * Ajoute un fait à la base de fait.
                 *
                 * @param[in] fait
                 * Le fait à ajouter à la base de faits. @see FaitAbstrait
                 * @throws ExceptionFaitDejaAjoute
                 * Le fait existe déjà et ne peut pas être modifié.
                 * */
                void ajouter( const FaitAbstrait::PtrFaitAbstrait & fait );

            protected:

                /**
                * La liste de tout les faits. @see FaitAbstrait.
                * */
                Contenu baseFait_;

        };

    }

}

#endif
