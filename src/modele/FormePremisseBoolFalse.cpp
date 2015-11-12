#include "FormePremisseBoolFalse.hpp"

namespace sysexp
{
    namespace modele
    {

        FormePremisseBoolFalse::FormePremisseBoolFalse( const std::string & nom ):
            FormeAbstraitePremisse( nom )
        { }

        void FormePremisseBoolFalse::accept( const PtrVisiteurFormeAbstrait & visiteur )
        {
            visiteur->visiter( this );
        }

    }
}
