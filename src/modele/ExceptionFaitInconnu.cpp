#include "ExceptionFaitInconnu.hpp"

namespace sysexp
{

    namespace modele
    {

        ExceptionFaitInconnu::ExceptionFaitInconnu( const std::string & erreur ):
            erreur_( erreur )
        { }

        const char* ExceptionFaitInconnu::what() const throw()
        {
            return erreur_.c_str();
        }

    }

}
