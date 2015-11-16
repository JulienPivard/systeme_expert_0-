#include "FormeConclusionBoolFalse.hpp"

namespace sysexp
{
    namespace modele
    {

        FormeConclusionBoolFalse::FormeConclusionBoolFalse( const std::string & nom ):
            FormeAbstraiteConclusion( nom )
        { }

        void FormeConclusionBoolFalse::accept( const PtrVisiteurFormeAbstrait & visiteur )
        {
            visiteur->visiter( *this );
        }

    }
}
