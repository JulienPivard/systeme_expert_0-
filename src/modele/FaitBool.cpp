#include "FaitBool.hpp"

namespace sysexp
{
    namespace modele
    {
        FaitBool::FaitBool( const std::string & nom, const bool & valeur ):
            FaitAbstrait( nom, TypeFait::faitBool ),
            valeur_( valeur )
        {
        }

        bool
        FaitBool::lireValeur() const
        {
            return valeur_;
        }
    }
}
