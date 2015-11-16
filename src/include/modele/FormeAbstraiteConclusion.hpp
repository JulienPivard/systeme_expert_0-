/**
 * @file FormeAbstraiteConclusion.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier FormeAbstraiteConclusion.cpp.
 * Définit la classe abstraite FormeAbstraiteConclusion.
 * */


#ifndef formeabstraiteconclusion_hpp
#define formeabstraiteconclusion_hpp

#include <string>
#include <memory>

#include "FormeAbstraite.hpp"


namespace sysexp
{

    namespace modele
    {

        /**
         * @brief Le squelette de représentation d'une conclusion.
         *
         * Déclaration de la classe FormeAbstraiteConclusion.
         * */
        class FormeAbstraiteConclusion : public FormeAbstraite
        {

            public:

                /**
                 * @typedef PtrFormeAbstraiteConclusion
                 *
                 * Alias pour faciliter l'utilisation d'un shared_ptr de FormeAbstraiteConclusion.
                 * */
                typedef std::shared_ptr< FormeAbstraiteConclusion > PtrFormeAbstraiteConclusion;

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] nom
                 * Le @ref nom_ de la conclusion abstraite.
                 * */
                FormeAbstraiteConclusion( const std::string & nom );

                /**
                 * Destructeur rendu virtuel.
                 * */
                virtual ~FormeAbstraiteConclusion() = default;

            public:

                FormeAbstraiteConclusion( const FormeAbstraiteConclusion & autre ) = delete;

                FormeAbstraiteConclusion & operator=( const FormeAbstraiteConclusion & autre ) = delete;

        };

    }
}

#endif
