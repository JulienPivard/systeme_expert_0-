#include "RegleAbstraite.hpp"

namespace sysexp
{
    namespace modele
    {

        RegleAbstraite::RegleAbstraite( const FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion & conclusion ):
            conclusion_( conclusion )
        { }

        void RegleAbstraite::ajouterSuccesseur( const PtrRegleAbstraite & successeur )
        {
            successeur_ = successeur;
        }

    }
}
