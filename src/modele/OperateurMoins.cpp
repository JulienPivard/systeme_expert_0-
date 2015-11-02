#include "OperateurMoins.hpp"

namespace sysexp
{
    namespace modele
    {

        OperateurMoins::OperateurMoins( const ValeurAbstraite::Valeur & filsGauche, const ValeurAbstraite::Valeur & filsDroit ):
            OperateurAbstrait( filsGauche, filsDroit )
        {
        }

        long int
        OperateurMoins::interpret( const BaseFait & baseFait ) const
        {
            return filsGauche_->interpret( baseFait ) - filsDroit_->interpret( baseFait );
        }

    }
}
