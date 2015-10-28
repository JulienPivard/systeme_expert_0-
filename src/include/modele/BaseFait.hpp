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

#include <string>
#include <map>
#include "Fait.hpp"

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
                 * @typedef Contenu
                 *
                 * Nouveau non pour la map.
                 * */
                typedef std::map<std::string, Fait> Contenu;

            public:

                /*
                 * Affiche le contenu de la base de fait.
                 * */
                //void afficher() const;

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
                 * @return Le fait trouvé.
                 * */
                const Fait & trouver( const std::string & nomFait ) const;

                /**
                 * Ajoute un fait à la base de fait.
                 *
                 * @param[in] fait
                 * Le fait à ajouter à la base de faits.
                 * */
                void ajouter( const Fait & fait );

            protected:
                /**
                * La liste de tout les faits.
                * */
                Contenu baseFait_;

        };

    }

}

#endif
