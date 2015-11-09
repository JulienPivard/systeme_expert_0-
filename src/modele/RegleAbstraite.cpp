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

    }
}
