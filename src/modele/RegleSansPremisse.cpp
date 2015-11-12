#include "RegleSansPremisse.hpp"

namespace sysexp
{
    namespace modele
    {

        RegleSansPremisse::RegleSansPremisse( const unsigned int & numeroRegle,
                const FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion & conclusion,
                const bool & traceExecution ):
            RegleAbstraite( numeroRegle, conclusion, traceExecution )
        { }

        bool RegleSansPremisse::verifierPremisses( const BaseFait::PtrBaseFait & base )
        {
            try
            {
                base->trouver("");
            }
            catch( ExceptionFaitInconnu & e )
            {
            }
            // Ici il n'y a pas de prémisses donc elles sont forcément vérifié.
            return true;
        }

    }
}
