#include "VisiteurForme.hpp"

namespace sysexp
{
    namespace modele
    {

        VisiteurForme::VisiteurForme( const BaseFait::PtrBaseFait & baseFait ):
            VisiteurFormeAbstrait( baseFait )
        { }

        void VisiteurForme::visiter( const FormeConclusionBoolTrue & conclusion )
        {
            FaitBool::PtrFaitBool fait( new FaitBool( conclusion.lireNom(), true ) );
            AjouterUnFait( fait );
        }

        void VisiteurForme::visiter( const FormeConclusionBoolFalse & conclusion )
        {
            FaitBool::PtrFaitBool fait( new FaitBool( conclusion.lireNom(), false ) );
            AjouterUnFait( fait );
        }

        void VisiteurForme::visiter( const FormeConclusionSymboliqueConstante & conclusion )
        {
            FaitSymbolique::PtrFaitSymbolique fait( new FaitSymbolique( conclusion.lireNom(), conclusion.lireValeur() ) );
            AjouterUnFait( fait );
        }

        void VisiteurForme::visiter( const FormeConclusionSymboliqueFait & conclusion )
        {

            // On vérifie que le nom du fait dont on veut récupérer la valeur existe.
            if( baseFait_->appartient( conclusion.lireNomFait() ) )
            {
                // On récupère le fait.
                FaitAbstrait::PtrFaitAbstrait faitTrouve = baseFait_->trouver( conclusion.lireNomFait() );
                // On sait que le fait trouvé est forcement un fait symbolique.
                const FaitSymbolique* faitSymboTrouve = static_cast< const FaitSymbolique* >( faitTrouve.get() );
                // Lecture de la valeur.
                try
                {
                    std::string valeur = faitSymboTrouve->lireValeur();
                    FaitSymbolique::PtrFaitSymbolique fait( new FaitSymbolique( conclusion.lireNom(), valeur ) );
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

        void VisiteurForme::visiter( const FormeConclusionEntierExpression & conclusion )
        {

            try
            {
                const long int valeur = conclusion.lireValeur( baseFait_ );
                FaitEntier::PtrFaitEntier fait( new FaitEntier( conclusion.lireNom(), valeur ) );
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

        void VisiteurForme::visiter( const FormeConclusionEntierFait & conclusion )
        {

            // On vérifie que le nom du fait dont on veut récupérer la valeur existe.
            if( baseFait_->appartient( conclusion.lireNomFait() ) )
            {
                // On récupère le fait.
                FaitAbstrait::PtrFaitAbstrait faitTrouve = baseFait_->trouver( conclusion.lireNomFait() );
                // On sait que le fait trouvé est forcement un fait symbolique.
                const FaitEntier* faitEntierTrouve = static_cast< const FaitEntier* >( faitTrouve.get() );
                // Lecture de la valeur.
                try
                {
                    long int valeur = faitEntierTrouve->lireValeur();
                    FaitEntier::PtrFaitEntier fait( new FaitEntier( conclusion.lireNom(), valeur ) );
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

        void VisiteurForme::visiter( const FormePremisseBoolTrue & premisse )
        {

            std::string nom = premisse.lireNom();
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

        void VisiteurForme::visiter( const FormePremisseBoolFalse & premisse )
        {

            std::string nom = premisse.lireNom();
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

        void VisiteurForme::visiter( const FormePremisseEntierExpression & premisse )
        {

            std::string nom = premisse.lireNom();
            if( baseFait_->appartient( nom ) )
            {
                // On récupère le fait.
                FaitAbstrait::PtrFaitAbstrait faitTrouve = baseFait_->trouver( nom );
                // On cast en fait entier.
                const FaitEntier* faitEntierTrouve = static_cast< const FaitEntier* >( faitTrouve.get() );
                try
                {
                    // On tente de récupérer la valeur de l'expression à laquelle on doit comparer celle du fait.
                    long int valeurExpression = premisse.lireValeur( baseFait_ );
                    // On compare la valeur du fait et celle de l'expression.
                    premisseVerifiee_ = premisse.test(faitEntierTrouve->lireValeur(), valeurExpression );
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

        void VisiteurForme::visiter( const FormePremisseEntierFait & premisse )
        {

            // On récupere les nom des deux fait à comparer.
            const std::string & nom = premisse.lireNom();
            const std::string & autreNom = premisse.lireNomAutreFait();
            // On vérifie que les deux fait existe bien dans la base de fait.
            if( baseFait_->appartient( nom ) && baseFait_->appartient( autreNom ) )
            {
                // On récupère les deux fait et on les cast.
                FaitAbstrait::PtrFaitAbstrait faitTrouve = baseFait_->trouver( nom );
                const FaitEntier* faitEntierTrouve = static_cast< const FaitEntier* >( faitTrouve.get() );

                FaitAbstrait::PtrFaitAbstrait autreFaitTrouve = baseFait_->trouver( autreNom );
                const FaitEntier* autreFaitEntierTrouve = static_cast< const FaitEntier* >( autreFaitTrouve.get() );
                // On test les deux valeurs.
                premisseVerifiee_ = premisse.test( faitEntierTrouve->lireValeur(), autreFaitEntierTrouve->lireValeur() );
            }

        }

        void VisiteurForme::visiter( const FormePremisseSymboliqueConstante & premisse )
        {

            const std::string & nomFait = premisse.lireNom();
            if( baseFait_->appartient( nomFait ) )
            {
                // On récupère le fait et on le cast.
                FaitAbstrait::PtrFaitAbstrait faitTrouve = baseFait_->trouver( nomFait );
                const FaitSymbolique* faitSymboliqueTrouve = static_cast< const FaitSymbolique* >( faitTrouve.get() );

                // On test le fait et sa valeur.
                premisseVerifiee_ = premisse.test( faitSymboliqueTrouve->lireValeur(), premisse.lireValeur() );
            }

        }

        void VisiteurForme::visiter( const FormePremisseSymboliqueFait & premisse )
        {

            const std::string & nomFait = premisse.lireNom();
            const std::string & nomAutreFait = premisse.lireNomAutreFait();
            // On vérifie que les deux fait existe bien dans la base de fait.
            if( baseFait_->appartient( nomFait ) && baseFait_->appartient( nomAutreFait ) )
            {
                // On récupère les deux fait et on les cast.
                FaitAbstrait::PtrFaitAbstrait faitTrouve = baseFait_->trouver( nomFait );
                const FaitSymbolique* faitSymboliqueTrouve = static_cast< const FaitSymbolique* >( faitTrouve.get() );

                FaitAbstrait::PtrFaitAbstrait autreFaitTrouve = baseFait_->trouver( nomAutreFait );
                const FaitSymbolique* autreFaitSymboliqueTrouve = static_cast< const FaitSymbolique* >( autreFaitTrouve.get() );
                // On test les deux valeurs.
                premisseVerifiee_ = premisse.test( faitSymboliqueTrouve->lireValeur(), autreFaitSymboliqueTrouve->lireValeur() );
            }

        }

    }
}
