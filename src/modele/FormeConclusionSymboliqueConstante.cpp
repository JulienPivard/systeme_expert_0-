#include "FormeConclusionSymboliqueConstante.hpp"

namespace sysexp
{
    namespace modele
    {

        FormeConclusionSymboliqueConstante::FormeConclusionSymboliqueConstante( const std::string & nom, const std::string & valeur ):
            FormeAbstraiteConclusion( nom ),
            valeur_( valeur )
        { }

        void FormeConclusionSymboliqueConstante::accept( const PtrVisiteurFormeAbstrait & visiteur )
        {
            visiteur->visiter( *this );
        }

        const std::string & FormeConclusionSymboliqueConstante::lireValeur() const
        {
            return valeur_;
        }

    }
}
