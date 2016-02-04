#include "ExceptionDivParZero.hpp"

namespace sysexp
{

    namespace modele
    {

        ExceptionDivParZero::ExceptionDivParZero( const std::string & erreur ):
            erreur_( erreur )
        { }

        const char* ExceptionDivParZero::what() const throw()
        {
            return erreur_.c_str();
        }

    }

}
