#include "RegleAvecPremisse.hpp"

namespace sysexp
{
    namespace modele
    {

        RegleAvecPremisse::RegleAvecPremisse( const FormeAbstraitePremisse::PtrFormeAbstraitePremisse & premisse, const FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion & conclusion ):
            RegleAbstraite( conclusion )
        {
            ajouterPremisse( premisse );
        }

        void RegleAvecPremisse::ajouterPremisse( const FormeAbstraitePremisse::PtrFormeAbstraitePremisse & premisse )
        {
            premisses_.insert( premisse );
        }

        void RegleAvecPremisse::accept( const VisiteurFormeAbstrait::PtrVisiteurFormeAbstrait & visiteur )
        {
            declenchee_ = visiteur->getConclusionDeclenchee();
        }

    }
}
