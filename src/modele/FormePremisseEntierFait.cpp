#include "FormePremisseEntierFait.hpp"

namespace sysexp
{

    namespace modele
    {

        FormePremisseEntierFait::FormePremisseEntierFait( const std::string & nomFait,
                        FormeAbstraitePremisse::OperateurComparaisonEntier comparateur,
                        const std::string & nomAutreFait ):
            FormeAbstraitePremisse( nomFait ),
            signe_( comparateur ),
            nomAutreFait_( nomAutreFait )
        { }


        void FormePremisseEntierFait::accept( const PtrVisiteurFormeAbstrait & visiteur )
        {
            visiteur->visiter( *this );
        }

        bool FormePremisseEntierFait::test( const long int & partieGauche, const long int & partieDroite ) const
        {
            return signe_( partieGauche, partieDroite );
        }

        const std::string & FormePremisseEntierFait::lireNomAutreFait() const
        {
            return nomAutreFait_;
        }

    }

}
