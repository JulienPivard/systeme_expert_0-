#include "OperateurDiv.hpp"

namespace sysexp
{
    namespace modele
    {

        OperateurDiv::OperateurDiv( const ValeurAbstraite::Valeur & filsGauche, const ValeurAbstraite::Valeur & filsDroit ):
            OperateurAbstrait( filsGauche, filsDroit )
        { }

        long int
        OperateurDiv::interpret( const BaseFait & baseFait ) const
        {
            return filsGauche_->interpret( baseFait ) / filsDroit_->interpret( baseFait );
        }
    }
}
