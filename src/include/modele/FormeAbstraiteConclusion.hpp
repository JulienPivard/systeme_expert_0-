/**
 * @file FormeAbstraiteConclusion.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier FormeAbstraiteConclusion.cpp.
 * Définit la classe abstraite FormeAbstraiteConclusion.
 * */


#ifndef formeabstraiteconclusion_hpp
#define formeabstraiteconclusion_hpp

#include <string>

#include "FormeAbstraite.hpp"

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
         * @class FormeAbstraiteConclusion FormeAbstraiteConclusion.hpp
         *
         * Déclaration de la classe FormeAbstraiteConclusion.
         * */
        class FormeAbstraiteConclusion : public FormeAbstraite
        {

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] nom
                 * Le nom de la conclusion abstraite.
                 * */
                FormeAbstraiteConclusion( const std::string & nom );

                /**
                 * Destructeur rendu virtuel.
                 * */
                virtual ~FormeAbstraiteConclusion() = default;

        };

    }
}

#endif
