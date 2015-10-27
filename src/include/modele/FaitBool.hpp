/*Pivard Julien*/

#ifndef faitbool_hpp
#define faitbool_hpp

#include "Fait.hpp"

namespace sysexp
{
    namespace modele
    {
        class FaitBool : public Fait
        {

            public:
                FaitBool( const std::string & nom, const bool & valeur );
                bool lireValeur() const;

            protected:
                const bool valeur_;

        };
    }
}

#endif

/*Pivard Julien*/
