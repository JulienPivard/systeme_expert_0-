#include "OperateurPlus.hpp"

namespace sysexp
{
    namespace modele
    {

        OperateurPlus::OperateurPlus( ValeurAbstraite::Valeur filsGauche, ValeurAbstraite::Valeur filsDroit ):
            filsGauche_( filsGauche ),
            filsDroit_( filsDroit )
        { }

        long int
        OperateurPlus::interpret( const BaseFait & baseFait ) const
        {
            return filsGauche_->interpret( baseFait ) + filsDroit_->interpret( baseFait );
        }

    }

}
