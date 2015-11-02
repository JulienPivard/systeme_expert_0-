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

        long int
        FeuilleConstante::interpret( const BaseFait & baseFait ) const
        {
            // oui c'est bien crade comme y faut mais j'en ai mare du warning associé
            baseFait.appartient("");
            return valeur_;
        }

    }
}
