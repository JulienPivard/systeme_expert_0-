#include "FormeConclusionEntierFait.hpp"

namespace sysexp
{
    namespace modele
    {

        FormeConclusionEntierFait::FormeConclusionEntierFait( const std::string & nom, const std::string & nomFait ):
            FormeAbstraiteConclusion( nom ),
            nomFait_( nomFait )
        { }

        void FormeConclusionEntierFait::accept( const PtrVisiteurFormeAbstrait & visiteur )
        {
            visiteur->visiter( *this );
        }

        const std::string & FormeConclusionEntierFait::lireNomFait() const
        {
            return nomFait_;
        }

    }
}
