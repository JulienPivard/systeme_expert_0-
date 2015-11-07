#include "FormeConclusionBoolTrue.hpp"

namespace sysexp
{
    namespace modele
    {

        FormeConclusionBoolTrue::FormeConclusionBoolTrue( const std::string & nom ):
            FormeAbstraiteConclusion( nom )
        { }

        void FormeConclusionBoolTrue::accept( const PtrVisiteurFormeAbstrait & visiteur )
        {
            visiteur->visiter( this );
        }

    }
}
