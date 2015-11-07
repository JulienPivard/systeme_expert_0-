#include "OperateurPlus.hpp"

namespace sysexp
{
    namespace modele
    {

        OperateurPlus::OperateurPlus( const ValeurAbstraite::PtrValeur & filsGauche, const ValeurAbstraite::PtrValeur & filsDroit ):
            OperateurAbstrait( filsGauche, filsDroit )
        { }

        long int
        OperateurPlus::interpret( const BaseFait & baseFait ) const
        {
            return filsGauche_->interpret( baseFait ) + filsDroit_->interpret( baseFait );
        }

    }

}
