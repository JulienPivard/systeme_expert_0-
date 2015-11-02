#include "FaitAbstrait.hpp"

namespace sysexp
{
    namespace modele
    {

        FaitAbstrait::FaitAbstrait( const std::string & nom, const TypeFait & type ):
            nom_( nom ),
            type_( type )
        {
        }

        const std::string &
        FaitAbstrait::lireNom() const
        {
            return nom_;
        }

        const TypeFait &
        FaitAbstrait::type() const
        {
            return type_;
        }

    }
}
