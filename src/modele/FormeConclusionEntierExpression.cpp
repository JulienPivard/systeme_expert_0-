#include "FormeConclusionEntierExpression.hpp"

namespace sysexp
{
    namespace modele
    {

        FormeConclusionEntierExpression::FormeConclusionEntierExpression( const std::string & nom, const ValeurAbstraite::PtrValeur & valeur ):
            FormeAbstraiteConclusion( nom ),
            valeur_( valeur )
        { }

        void FormeConclusionEntierExpression::accept( const PtrVisiteurFormeAbstrait & visiteur )
        {
            visiteur->visiter( *this );
        }

        long int FormeConclusionEntierExpression::lireValeur( const BaseFait::PtrBaseFait & baseFait ) const
        {
            BaseFait * base = baseFait.get();
            return valeur_->interpret( *base );
        }

    }
}
