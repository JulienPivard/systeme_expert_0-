#include "FormePremisseEntierExpression.hpp"

namespace sysexp
{
    namespace modele
    {

        FormePremisseEntierExpression::FormePremisseEntierExpression( const std::string & nomFait,
                FormeAbstraitePremisse::OperateurComparaisonEntier comparateur,
                const ValeurAbstraite::PtrValeur & expression ):
            FormeAbstraitePremisse( nomFait ),
            signe_( comparateur ),
            expression_( expression )
        { }

        void FormePremisseEntierExpression::accept( const PtrVisiteurFormeAbstrait & visiteur )
        {
            visiteur->visiter( *this );
        }

        bool FormePremisseEntierExpression::test( const long int & partieGauche, const long int & partieDroite ) const
        {
            return signe_( partieGauche, partieDroite );
        }

        long int FormePremisseEntierExpression::lireValeur( const BaseFait::PtrBaseFait & baseFait ) const
        {
            BaseFait * base = baseFait.get();
            return expression_->interpret( *base );
        }

    }
}
