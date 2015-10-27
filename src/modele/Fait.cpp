#include <cstdlib>

#include "Fait.hpp"

namespace sysexp
{
    namespace modele
    {
        Fait::Fait( const std::string & nom ):
            nom_(nom)
        {
        }

        const std::string &
        Fait::lireNom() const
        {
            return nom_;
        }
    }
}
