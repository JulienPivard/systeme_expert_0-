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

        void RegleAbstraite::verifFlagErreurVisiteur( const VisiteurFormeAbstrait::PtrVisiteurFormeAbstrait & visiteur ) const
        {
            if( visiteur->getCodeErreurExecution() == Erreurs::divParZero )
            {
                std::cerr << "Erreur division par zéro dans la règle : "
                    << numeroRegle_
                    << "."
                    << std::endl;
                throw ExceptionDivParZero();
            }
            if( visiteur->getCodeErreurExecution() == Erreurs::incoherenceFait )
            {
                std::cerr << "Erreur La base de fait est incohérente,"
                    << " la règle : "
                    << numeroRegle_
                    << " à déjà été ajoutée avec une autre valeur."
                    << std::endl;
                throw ExceptionFaitDejaAjoute();
            }
        }

        bool RegleAbstraite::declencher( const BaseFait::PtrBaseFait & base )
        {
            VisiteurForme::PtrVisiteurForme visiteur( new VisiteurForme( base ) );
            conclusion_->accept( visiteur );
            declenchee_ = visiteur->getConclusionDeclenchee();
            // Pour mieux voir ce qui se passe lors du déclenchement.
            std::cout << std::endl
                << "Règle numéro "
                << numeroRegle_
                << " nom "
                << conclusion_->lireNom()
                << std::endl;
            visiteur->afficher();
            // Fin de debogage.
            // Vérification des flags d'erreur du visiteur.
            verifFlagErreurVisiteur( visiteur );
            return declenchee_;
        }

        bool RegleAbstraite::iter( const BaseFait::PtrBaseFait & base )
        {
            bool resultat = false;
            // On test si toutes les prémisse ont pu se déclencher.
            if( verifierPremisses( base ) )
            {
                // On récupère le résultat de notre propre déclenchement.
                resultat = declencher( base );
            }
            bool resultatSuccesseur = false;
            if( possedeSuccesseur() )
            {
                // On récupère le résultat du déclenchement du successeur.
                resultatSuccesseur = successeur_->iter( base );
            }
            return resultat || resultatSuccesseur;
        }

    }
}
