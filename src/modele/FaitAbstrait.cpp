#include <cstdlib>

#include "FaitAbstrait.hpp"

namespace sysexp
{
    namespace modele
    {
        FaitAbstrait::FaitAbstrait( const std::string & nom ):
            nom_( nom )
        {
        }

        const std::string &
        FaitAbstrait::lireNom() const
        {
            return nom_;
        }
    }
}
