#include "FormePremisseSymboliqueFait.hpp"

namespace sysexp
{
    namespace modele
    {

        FormePremisseSymboliqueFait::FormePremisseSymboliqueFait( const std::string & nomFait,
                        FormeAbstraitePremisse::OperateurComparaisonString comparateur,
                        const std::string & nomAutreFait ):
            FormeAbstraitePremisse( nomFait ),
            signe_( comparateur ),
            nomAutreFait_( nomAutreFait )
        { }

        void
        FormePremisseSymboliqueFait::accept( const PtrVisiteurFormeAbstrait & visiteur )
        {
            visiteur->visiter( this );
        }

        bool
        FormePremisseSymboliqueFait::test( const std::string & partieGauche, const std::string & partieDroite ) const
        {
            return signe_( partieGauche, partieDroite );
        }

        const std::string &
        FormePremisseSymboliqueFait::lireNomAutreFait() const
        {
            return nomAutreFait_;
        }

    }
}
