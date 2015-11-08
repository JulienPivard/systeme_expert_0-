#include "SigneSuperieurEgal.hpp"

namespace sysexp
{
    namespace modele
    {

        bool SigneSuperieurEgal::comparer( const long int & partieGauche, const long int & partieDroite ) const
        {
            return partieGauche >= partieDroite;
        }

        bool SigneSuperieurEgal::comparer( const std::string & partieGauche, const std::string & partieDroite ) const
        {
            throw "Impossible de comparer des chaines de cette façons.";
        }

    }
}
