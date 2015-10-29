#include <cstdlib>

#include "FaitSymbolique.hpp"

namespace sysexp
{
    namespace modele
    {

        FaitSymbolique::FaitSymbolique( const std::string & nom, const std::string & valeur ):
            FaitAbstrait( nom ),
            valeur_( valeur )
        {
        }

        const std::string & FaitSymbolique::lireValeur() const
        {
            return valeur_;
        }

    }
}
