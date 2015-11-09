#include "RegleSansPremisse.hpp"

namespace sysexp
{
    namespace modele
    {

        RegleSansPremisse::RegleSansPremisse( const unsigned int & numeroRegle, const FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion & conclusion ):
            RegleAbstraite( numeroRegle, conclusion )
        { }

        bool RegleSansPremisse::declencher( const BaseFait::PtrBaseFait & base )
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

        bool RegleSansPremisse::iter( const BaseFait::PtrBaseFait & base )
        {
            // On récupère le résultat de notre propre déclenchement.
            bool resultat = declencher( base );
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
