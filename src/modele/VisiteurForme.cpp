#include "VisiteurForme.hpp"

#include "FormeConclusionBoolTrue.hpp"
#include "FormeConclusionBoolFalse.hpp"
#include "FormeConclusionEntierFait.hpp"
#include "FormeConclusionEntierExpression.hpp"
#include "FormeConclusionSymboliqueConstante.hpp"
#include "FormeConclusionSymboliqueFait.hpp"

#include "FaitAbstrait.hpp"

namespace sysexp
{
    namespace modele
    {

        VisiteurForme::VisiteurForme( const BaseFait::PtrBaseFait & baseFait ):
            VisiteurFormeAbstrait( baseFait )
        { }

        void VisiteurForme::visiter( const FormeConclusionBoolTrue * conclusion )
        {

            FaitBool::PtrFaitBool fait( new FaitBool( conclusion->lireNom(), true ) );
            AjouterUnFait( fait );

        }

        void VisiteurForme::visiter( const FormeConclusionBoolFalse * conclusion )
        {
            FaitBool::PtrFaitBool fait( new FaitBool( conclusion->lireNom(), false ) );
            AjouterUnFait( fait );
        }

        void VisiteurForme::visiter( const FormeConclusionSymboliqueConstante * conclusion )
        {
            FaitSymbolique::PtrFaitSymbolique fait( new FaitSymbolique( conclusion->lireNom(), conclusion->lireValeur() ) );
            AjouterUnFait( fait );
        }

        void VisiteurForme::visiter( const FormeConclusionSymboliqueFait * conclusion )
        {

            // On vérifie que le nom du fait dont on veut récupérer la valeur existe.
            if( baseFait_->appartient( conclusion->lireNomFait() ) )
            {
                // On récupère le fait.
                FaitAbstrait::PtrFaitAbstrait faitTrouve = baseFait_->trouver( conclusion->lireNomFait() );
                // On sait que le fait trouvé est forcement un fait symbolique.
                const FaitSymbolique* faitSymboTrouve = static_cast< const FaitSymbolique* >( faitTrouve.get() );
                // Lecture de la valeur.
                std::string valeur = faitSymboTrouve->lireValeur();
                FaitSymbolique::PtrFaitSymbolique fait( new FaitSymbolique( conclusion->lireNom(), valeur ) );
                AjouterUnFait( fait );
            }

        }

        void VisiteurForme::visiter( const FormeConclusionEntierExpression * conclusion )
        {
            FaitEntier::PtrFaitEntier fait( new FaitEntier( conclusion->lireNom(), conclusion->lireValeur( baseFait_ ) ) );
            AjouterUnFait( fait );
        }

        void VisiteurForme::visiter( const FormeConclusionEntierFait * conclusion )
        {

            // On vérifie que le nom du fait dont on veut récupérer la valeur existe.
            if( baseFait_->appartient( conclusion->lireNomFait() ) )
            {
                // On récupère le fait.
                FaitAbstrait::PtrFaitAbstrait faitTrouve = baseFait_->trouver( conclusion->lireNomFait() );
                // On sait que le fait trouvé est forcement un fait symbolique.
                const FaitEntier* faitEntierTrouve = static_cast< const FaitEntier* >( faitTrouve.get() );
                // Lecture de la valeur.
                long int valeur = faitEntierTrouve->lireValeur();
                FaitEntier::PtrFaitEntier fait( new FaitEntier( conclusion->lireNom(), valeur ) );
                AjouterUnFait( fait );
            }

        }

    }
}
