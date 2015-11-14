#include "MoteurInference.hpp"

namespace sysexp
{
    namespace modele
    {

        MoteurInference::MoteurInference( const RegleAbstraite::PtrRegleAbstraite & baseDeRegles ):
            baseDeRegles_( baseDeRegles )
        {
            creerInstanceBaseFaits();
        }

        void MoteurInference::creerInstanceBaseFaits()
        {
            baseFaits_ = BaseFait::PtrBaseFait( new BaseFait() );
        }

        void MoteurInference::analyserBaseRegles()
        {
            bool iterer;
            do
            {
                iterer = baseDeRegles_->iter( baseFaits_ );
            } while( iterer );
        }

        void MoteurInference::afficherBaseFaits()
        {
            baseFaits_->afficher();
        }

    }
}
