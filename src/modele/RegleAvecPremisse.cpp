#include "RegleAvecPremisse.hpp"

namespace sysexp
{
    namespace modele
    {

        RegleAvecPremisse::RegleAvecPremisse( const unsigned int & numeroRegle, const FormeAbstraitePremisse::PtrFormeAbstraitePremisse & premisse, const FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion & conclusion ):
            RegleAbstraite( numeroRegle, conclusion )
        {
            ajouterPremisse( premisse );
        }

        void RegleAvecPremisse::ajouterPremisse( const FormeAbstraitePremisse::PtrFormeAbstraitePremisse & premisse )
        {
            premisses_.insert( premisse );
        }

        bool RegleAvecPremisse::verifierPremisses( const BaseFait::PtrBaseFait & base )
        {
            bool resultat = true;
            for( const FormeAbstraitePremisse::PtrFormeAbstraitePremisse & prem : premisses_ )
            {
                VisiteurForme::PtrVisiteurForme visiteur( new VisiteurForme( base ) );
                prem->accept( visiteur );
                resultat = resultat && visiteur->getPremisseVerifiee();
                if( !resultat )
                {
                    break;
                }
            }
            return resultat;
        }

    }
}
