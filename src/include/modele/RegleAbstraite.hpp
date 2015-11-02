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

                /**
                * Destructeur de la RegleAbstraite.
                * */
                virtual ~RegleAbstraite();

            protected:
                /**
                 *
                 * */
                Conclusion conclusion_

        };

    }
}

#endif
