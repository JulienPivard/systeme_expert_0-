#include <cstdlib>

#include "OperateurAbstrait.hpp"

namespace sysexp
{
    namespace modele
    {

        OperateurAbstrait::OperateurAbstrait( const ValeurAbstraite::Valeur & filsGauche, const ValeurAbstraite::Valeur & filsDroit ):
            filsGauche_( filsGauche ),
            filsDroit_( filsDroit )
        { }
    }
}
