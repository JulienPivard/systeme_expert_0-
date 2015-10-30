#include <cstdlib>

#include "FeuilleFait.hpp"
#include "FaitEntier.hpp"
#include "FaitAbstrait.hpp"

namespace sysexp
{
    namespace modele
    {

        FeuilleFait::FeuilleFait( const std::string & nom ):
            nom_( nom )
        { }

        const long int &
        FeuilleFait::interpret( const BaseFait & baseFait ) const
        {
            if( baseFait.appartient( nom_ ) )
            {
                FaitEntier::PtrFaitEntier fait = std::dynamic_pointer_cast<FaitEntier>( baseFait.trouver( nom_ ));
                return fait->lireValeur();
            }
            return 0;
        }

    }
}
