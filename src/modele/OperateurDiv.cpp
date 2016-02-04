#include "OperateurDiv.hpp"

namespace sysexp
{

    namespace modele
    {

        OperateurDiv::OperateurDiv( const ValeurAbstraite::PtrValeur & filsGauche, const ValeurAbstraite::PtrValeur & filsDroit ):
            OperateurAbstrait( filsGauche, filsDroit )
        { }

        long int
        OperateurDiv::interpret( const BaseFait & baseFait ) const
        {
            if( filsDroit_->interpret( baseFait ) == 0 )
            {
                int valeurGauche = filsGauche_->interpret( baseFait );
                std::ostringstream stream;
                stream << "L'opération "
                    << valeurGauche
                    << "/0 ne peut pas être effectué.";
                throw ExceptionDivParZero( stream.str() );
            }
            return filsGauche_->interpret( baseFait ) / filsDroit_->interpret( baseFait );
        }

    }

}
