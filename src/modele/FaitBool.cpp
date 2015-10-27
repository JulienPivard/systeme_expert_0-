#include <cstdlib>

#include "FaitBool.hpp"

namespace sysexp
{
    namespace modele
    {
        FaitBool::FaitBool( const std::string & nom, const bool & valeur ):
            Fait(nom),
            valeur_(valeur)
        {
        }

        bool
        FaitBool::lireValeur() const
        {
            return valeur_;
        }
    }
}
