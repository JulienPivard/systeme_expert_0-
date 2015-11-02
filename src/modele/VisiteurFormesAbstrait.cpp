#include "VisiteurFormesAbstrait.hpp"

namespace sysexp
{
    namespace modele
    {
        VisiteurFormesAbstrait::VisiteurFormesAbstrait( const VisiteurFormesAbstrait::PtrBaseFait & baseFait ):
            baseFait_( baseFait ),
            premisseVerifiee_( false ),
            conclusionDeclenchee_( false ),
            erreur_( Erreurs::toutVaBien )
        { }

        void VisiteurFormesAbstrait::visiterConclusionBool()
        {
            conclusionDeclenchee_ = false;
        }

        bool VisiteurFormesAbstrait::getPremisseVerifiee() const
        {
            return premisseVerifiee_;
        }

        bool VisiteurFormesAbstrait::getConclusionDeclenchee() const
        {
            return conclusionDeclenchee_;
        }

        Erreurs VisiteurFormesAbstrait::getCodeErreurExecution() const
        {
            return erreur_;
        }

    }
}
