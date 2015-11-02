#include "FeuilleFait.hpp"

namespace sysexp
{
    namespace modele
    {

        FeuilleFait::FeuilleFait( const std::string & nom ):
            nom_( nom )
        { }

        long int
        FeuilleFait::interpret( const BaseFait & baseFait ) const
        {

            if( baseFait.appartient( nom_ ) )
            {
                FaitEntier::PtrFaitEntier fait = std::dynamic_pointer_cast<FaitEntier>( baseFait.trouver( nom_ ));
                return fait->lireValeur();
            }

            // On n'a pas trouvé le fait recherché.
            throw ExceptionFaitInconnu();
        }

    }
}
