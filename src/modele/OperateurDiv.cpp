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
            if( filsDroit_->interpret( baseFait ) == 0 )
            {
                throw ExceptionDivParZero();
            }
            return filsGauche_->interpret( baseFait ) / filsDroit_->interpret( baseFait );
        }
    }
}
