#include "RegleAbstraite.hpp"

namespace sysexp
{
    namespace modele
    {

        RegleAbstraite::RegleAbstraite( const unsigned int & numeroRegle, const FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion & conclusion ):
            numeroRegle_( numeroRegle ),
            conclusion_( conclusion ),
            successeur_( nullptr ),
            declenchee_( false )
        { }

        void RegleAbstraite::ajouterSuccesseur( const PtrRegleAbstraite & successeur )
        {
            successeur_ = successeur;
        }

        const RegleAbstraite::PtrRegleAbstraite & RegleAbstraite::lireSuccesseur() const
        {
            return successeur_;
        }

        bool RegleAbstraite::possedeSuccesseur() const
        {
            return successeur_ != nullptr;
        }

        bool RegleAbstraite::estDeclenchee() const
        {
            return declenchee_;
        }

    }
}
