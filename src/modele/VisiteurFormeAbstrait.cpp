#include "VisiteurFormeAbstrait.hpp"

namespace sysexp
{
    namespace modele
    {

        VisiteurFormeAbstrait::VisiteurFormeAbstrait( const BaseFait::PtrBaseFait & baseFait ):
            baseFait_( baseFait ),
            premisseVerifiee_( false ),
            conclusionDeclenchee_( false ),
            erreur_( Erreurs::toutVaBien )
        { }

        bool VisiteurFormeAbstrait::getPremisseVerifiee() const
        {
            return premisseVerifiee_;
        }

        bool VisiteurFormeAbstrait::getConclusionDeclenchee() const
        {
            return conclusionDeclenchee_;
        }

        Erreurs VisiteurFormeAbstrait::getCodeErreurExecution() const
        {
            return erreur_;
        }

        void VisiteurFormeAbstrait::AjouterUnFait( const FaitAbstrait::PtrFaitAbstrait & fait )
        {

            try
            {
                baseFait_->ajouter( fait );
                conclusionDeclenchee_  = true;
            }
            catch( ExceptionFaitDejaAjoute & e )
            {
                erreur_ = Erreurs::incoherenceFait;
            }

        }

    }
}
