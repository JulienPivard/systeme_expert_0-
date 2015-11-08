#include "RegleAbstraite.hpp"

namespace sysexp
{
    namespace modele
    {

        RegleAbstraite::RegleAbstraite( const FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion & conclusion ):
            conclusion_( conclusion ),
            successeur_( nullptr ),
            declenchee_( false )
        { }

        void RegleAbstraite::ajouterSuccesseur( const PtrRegleAbstraite & successeur )
        {
            successeur_ = successeur;
        }

        bool RegleAbstraite::estDeclenchee() const
        {
            return declenchee_;
        }

        bool RegleAbstraite::possedeSuccesseur() const
        {
            return successeur_ != nullptr;
        }

    }
}
