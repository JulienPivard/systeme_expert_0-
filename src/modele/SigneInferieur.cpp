#include "SigneInferieur.hpp"

namespace sysexp
{
    namespace modele
    {

        bool SigneInferieur::comparer( const long int & partieGauche, const long int & partieDroite ) const
        {
            return partieGauche < partieDroite;
        }

        bool SigneInferieur::comparer( const std::string & partieGauche, const std::string & partieDroite ) const
        {
            throw "Impossible de comparer des chaines de cette façons.";
        }

    }
}
