/**
 * @file RegleAbstraite.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier RegleAbstraite.cpp.
 * Définit la classe abstraite RegleAbstraite.
 * */


#ifndef regleabstraite_hpp
#define regleabstraite_hpp

#include <cstdlib>

#include "FormeAbstraiteConclusion.hpp"

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
        * @class RegleAbstraite RegleAbstraite.hpp
        *
        * Déclaration de la classe RegleAbstraite.
        * */
        class RegleAbstraite
        {

            public:

                RegleAbstraite( const FormeAbstraiteConclusion & conclusion )

                /**
                * Destructeur de la RegleAbstraite.
                * */
                virtual ~RegleAbstraite();

            protected:

                /**
                 * La conclusion de la règle.
                 * @see FormeAbstraiteConclusion
                 * */
                const FormeAbstraiteConclusion conclusion_;

                /**
                 * La règle suivante.
                 * */
                const RegleAbstraite successeur_;

        };

    }
}

#endif
