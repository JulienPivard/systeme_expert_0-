#include "SigneEgalEgal.hpp"

namespace sysexp
{
    namespace modele
    {

        bool SigneEgalEgal::comparer( const long int & partieGauche, const long int & partieDroite ) const
        {
            return partieGauche == partieDroite;
        }

        bool SigneEgalEgal::comparer( const std::string & partieGauche, const std::string & partieDroite ) const
        {
            return partieGauche == partieDroite;
        }

    }
}
