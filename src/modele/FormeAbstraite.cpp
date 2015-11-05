#include "FormeAbstraite.hpp"

namespace sysexp
{
    namespace modele
    {

        FormeAbstraite::FormeAbstraite( const std::string & nom ):
            nom_( nom )
        { }

        const std::string & FormeAbstraite::lireNom() const
        {
            return nom_;
        }

    }
}
