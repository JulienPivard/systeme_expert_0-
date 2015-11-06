#include "VisiteurForme.hpp"
#include "FormeConclusionBoolTrue.hpp"

namespace sysexp
{
    namespace modele
    {

        VisiteurForme::VisiteurForme( const BaseFait::PtrBaseFait & baseFait ):
            VisiteurFormeAbstrait( baseFait )
        { }

        void VisiteurForme::visiterConclusionBool( const FormeConclusionBoolTrue * conclusion )
        {
            FaitBool::PtrFaitBool fait( new FaitBool( conclusion->lireNom(), true ) );
            baseFait_->ajouter( fait );
        }

    }
}
