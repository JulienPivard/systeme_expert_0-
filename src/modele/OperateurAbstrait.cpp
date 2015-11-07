#include "OperateurAbstrait.hpp"

namespace sysexp
{
    namespace modele
    {

        OperateurAbstrait::OperateurAbstrait( const ValeurAbstraite::PtrValeur & filsGauche, const ValeurAbstraite::PtrValeur & filsDroit ):
            filsGauche_( filsGauche ),
            filsDroit_( filsDroit )
        { }

    }
}
