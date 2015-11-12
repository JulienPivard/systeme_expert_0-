#include "VisiteurForme.hpp"

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
                try
                {
                    std::string valeur = faitSymboTrouve->lireValeur();
                    FaitSymbolique::PtrFaitSymbolique fait( new FaitSymbolique( conclusion->lireNom(), valeur ) );
                    AjouterUnFait( fait );
                }
                catch( ExceptionFaitInconnu & e )
                {
                    erreur_ = Erreurs::incoherenceFait;
                }
            }
            else
            {
                erreur_ = Erreurs::faitSymboliqueInconnu;
            }

        }

        void VisiteurForme::visiter( const FormeConclusionEntierExpression * conclusion )
        {

            try
            {
                const long int valeur = conclusion->lireValeur( baseFait_ );
                FaitEntier::PtrFaitEntier fait( new FaitEntier( conclusion->lireNom(), valeur ) );
                AjouterUnFait( fait );
            }
            catch( ExceptionFaitInconnu & e )
            {
                erreur_ = Erreurs::faitExpressionInconnu;
            }
            catch( ExceptionDivParZero & e )
            {
                erreur_ = Erreurs::divParZero;
            }

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
                try
                {
                    long int valeur = faitEntierTrouve->lireValeur();
                    FaitEntier::PtrFaitEntier fait( new FaitEntier( conclusion->lireNom(), valeur ) );
                    AjouterUnFait( fait );
                }
                catch( ExceptionFaitInconnu & e )
                {
                    erreur_ = Erreurs::incoherenceFait;
                }
            }
            else
            {
                erreur_ = Erreurs::faitEntierInconnu;
            }

        }

        //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        void VisiteurForme::visiter( const FormePremisseBoolTrue * premisse )
        {

            std::string nom = premisse->lireNom();
            if( baseFait_->appartient( nom ) )
            {
                // On récupère le fait.
                FaitAbstrait::PtrFaitAbstrait faitTrouve = baseFait_->trouver( nom );
                // On cast le fait en booléen.
                const FaitBool* faitBoolTrouve = static_cast< const FaitBool* >( faitTrouve.get() );
                // Ici on test si le fait booléen vaut vrais.
                premisseVerifiee_ = faitBoolTrouve->lireValeur() == true;
            }

        }

        void VisiteurForme::visiter( const FormePremisseBoolFalse * premisse )
        {

            std::string nom = premisse->lireNom();
            if( baseFait_->appartient( nom ) )
            {
                // On récupère le fait.
                FaitAbstrait::PtrFaitAbstrait faitTrouve = baseFait_->trouver( nom );
                // On cast le fait en booléen.
                const FaitBool* faitBoolTrouve = static_cast< const FaitBool* >( faitTrouve.get() );
                // Ici on test si le fait booléen vaut vrais.
                premisseVerifiee_ = faitBoolTrouve->lireValeur() == false;
            }

        }

        void VisiteurForme::visiter( const FormePremisseEntierExpression * premisse )
        {
            std::string nom = premisse->lireNom();
            if( baseFait_->appartient( nom ) )
            {
                // On récupère le fait.
                FaitAbstrait::PtrFaitAbstrait faitTrouve = baseFait_->trouver( nom );
                // On cast en fait entier.
                const FaitEntier* faitEntierTrouve = static_cast< const FaitEntier* >( faitTrouve.get() );
                try
                {
                    long int valeurExpression = premisse->lireValeur( baseFait_ );
                    premisseVerifiee_ = premisse->test(faitEntierTrouve->lireValeur(), valeurExpression );
                }
                catch( ExceptionFaitInconnu & e )
                {
                    erreur_ = Erreurs::faitExpressionInconnu;
                }
                catch( ExceptionDivParZero & e )
                {
                    erreur_ = Erreurs::divParZero;
                }
            }
        }

        void VisiteurForme::visiter( const FormePremisseEntierFait * premisse )
        {
            std::string nom = premisse->lireNom();
        }

    }
}
