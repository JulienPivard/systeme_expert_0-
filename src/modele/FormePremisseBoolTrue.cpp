#include "FormePremisseBoolTrue.hpp"

namespace sysexp
{
    namespace modele
    {

        FormePremisseBoolTrue::FormePremisseBoolTrue( const std::string & nom ):
            FormeAbstraitePremisse( nom )
        { }

        void FormePremisseBoolTrue::accept( const PtrVisiteurFormeAbstrait & visiteur )
        {
            visiteur->visiter( *this );
        }

    }
}
