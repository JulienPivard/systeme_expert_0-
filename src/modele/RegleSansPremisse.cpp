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
                << "Règle "
                << conclusion_->lireNom()
                << std::endl;
            visiteur->afficher();
            // Fin de debogage.
            return declenchee_;
        }

        bool RegleSansPremisse::iter( const BaseFait::PtrBaseFait & base )
        {
            bool resMoi = declencher( base );
            bool resSuccesseur = false;
            if( possedeSuccesseur() )
            {
                resSuccesseur = successeur_->iter( base );
            }
            return resMoi || resSuccesseur;
        }

    }
}
