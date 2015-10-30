#include <cstdlib>

#include "FeuilleConstante.hpp"
#include "BaseFait.hpp"

namespace sysexp
{
    namespace modele
    {

        FeuilleConstante::FeuilleConstante( const long int & valeur ):
            valeur_( valeur )
        { }

        const long int &
        FeuilleConstante::interpret( const BaseFait & baseFait ) const
        {
            return valeur_;
        }

    }
}
