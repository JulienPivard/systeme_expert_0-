#include "FormeConclusionBoolTrue.hpp"

namespace sysexp
{
    namespace modele
    {

        FormeConclusionBoolTrue::FormeConclusionBoolTrue( const std::string & nom ):
            FormeAbstraiteConclusion( nom )
        { }

        void FormeConclusionBoolTrue::accept( const std::shared_ptr< VisiteurFormeAbstrait > & visiteur )
        {
            visiteur->visiterConclusionBool(this);
        }

    }
}
