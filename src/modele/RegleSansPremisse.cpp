#include "RegleSansPremisse.hpp"

namespace sysexp
{
    namespace modele
    {

        RegleSansPremisse::RegleSansPremisse( const FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion & conclusion ):
            RegleAbstraite( conclusion )
        { }

        void RegleSansPremisse::accept( const VisiteurFormeAbstrait::PtrVisiteurFormeAbstrait & visiteur )
        {
            conclusion_->accept( visiteur );
            declenchee_ = visiteur->getConclusionDeclenchee();
        }

    }
}
