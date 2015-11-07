#include "FormeConclusionSymboliqueFait.hpp"

namespace sysexp
{
    namespace modele
    {

        FormeConclusionSymboliqueFait::FormeConclusionSymboliqueFait( const std::string & nom, const std::string & nomFait ):
            FormeAbstraiteConclusion( nom ),
            nomFait_( nomFait )
        { }

        void FormeConclusionSymboliqueFait::accept( const PtrVisiteurFormeAbstrait & visiteur )
        {
            visiteur->visiter( this );
        }

        const std::string & FormeConclusionSymboliqueFait::lireNomFait() const
        {
            return nomFait_;
        }

    }
}
