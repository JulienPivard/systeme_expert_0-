#include "SigneDifferent.hpp"

namespace sysexp
{
    namespace modele
    {

        bool SigneDifferent::comparer( const long int & partieGauche, const long int & partieDroite ) const
        {
            return partieGauche != partieDroite;
        }

        bool SigneDifferent::comparer( const std::string & partieGauche, const std::string & partieDroite ) const
        {
            return partieGauche != partieDroite;
        }

    }
}
