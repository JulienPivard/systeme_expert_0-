#include "OperateurMul.hpp"

namespace sysexp
{
    namespace modele
    {

        OperateurMul::OperateurMul( const ValeurAbstraite::PtrValeur & filsGauche, const ValeurAbstraite::PtrValeur & filsDroit ):
            OperateurAbstrait( filsGauche, filsDroit )
        { }

        long int
        OperateurMul::interpret( const BaseFait & baseFait ) const
        {
            return filsGauche_->interpret( baseFait ) * filsDroit_->interpret( baseFait );
        }

    }
}
