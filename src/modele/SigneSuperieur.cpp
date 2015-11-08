#include "SigneSuperieur.hpp"

namespace sysexp
{
    namespace modele
    {

        bool SigneSuperieur::comparer( const long int & partieGauche, const long int & partieDroite ) const
        {
            return partieGauche > partieDroite;
        }

        bool SigneSuperieur::comparer( const std::string & partieGauche, const std::string & partieDroite ) const
        {
            throw "Impossible de comparer des chaines de cette façons.";
        }

    }
}
