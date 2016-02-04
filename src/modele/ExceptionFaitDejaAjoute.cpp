#include "ExceptionFaitDejaAjoute.hpp"

namespace sysexp
{

    namespace modele
    {

        ExceptionFaitDejaAjoute::ExceptionFaitDejaAjoute( const std::string & erreur ):
            erreur_( erreur )
        { }

        const char* ExceptionFaitDejaAjoute::what() const throw()
        {
            return erreur_.c_str();
        }

    }

}
