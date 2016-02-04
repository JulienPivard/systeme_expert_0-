#include "VisiteurFormeAbstrait.hpp"

namespace sysexp
{
    namespace modele
    {

        VisiteurFormeAbstrait::VisiteurFormeAbstrait( const BaseFait::PtrBaseFait & baseFait ):
            baseFait_( baseFait ),
            premisseVerifiee_( false ),
            conclusionDeclenchee_( false ),
            erreur_( Erreurs::toutVaBien ),
            messageErreur_( "" )
        { }

        bool VisiteurFormeAbstrait::getPremisseVerifiee() const
        {
            return premisseVerifiee_;
        }

        bool VisiteurFormeAbstrait::getConclusionDeclenchee() const
        {
            return conclusionDeclenchee_;
        }

        Erreurs VisiteurFormeAbstrait::getCodeErreurExecution() const
        {
            return erreur_;
        }

        std::string VisiteurFormeAbstrait::getMessageErreur() const
        {
            return messageErreur_;
        }

        void VisiteurFormeAbstrait::AjouterUnFait( const FaitAbstrait::PtrFaitAbstrait & fait )
        {

            try
            {
                baseFait_->ajouter( fait );
                conclusionDeclenchee_  = true;
            }
            catch( ExceptionFaitDejaAjoute & e )
            {
                erreur_ = Erreurs::incoherenceFait;
                messageErreur_ = e.what();
            }
            catch( ExceptionDivParZero & e )
            {
                erreur_ = Erreurs::divParZero;;
                messageErreur_ = e.what();
            }
            catch( ExceptionFaitInconnu & e )
            {
                erreur_ = Erreurs::incoherenceFait;
                messageErreur_ = e.what();
            }

        }

        void VisiteurFormeAbstrait::afficher() const
        {

            std::cout << "La prémisse à été déclenchée : "
                << std::boolalpha
                << getPremisseVerifiee()
                << std::endl;
            std::cout << "La conclusion à été déclenchée : "
                << std::boolalpha
                << getConclusionDeclenchee()
                << std::endl;
            std::cout << "Erreur d'exécution : ";

            switch( getCodeErreurExecution() )
            {

                case sysexp::modele::Erreurs::toutVaBien:
                    std::cout << "Pas d'erreur.";
                    break;

                case sysexp::modele::Erreurs::incoherenceFait:
                    std::cout << "La base est incohérente.";
                    break;

                case sysexp::modele::Erreurs::divParZero:
                    std::cout << "Division par zéro.";
                    break;

                case sysexp::modele::Erreurs::faitEntierInconnu:
                    std::cout << "Le fait entier n'existe pas.";
                    break;

                case sysexp::modele::Erreurs::faitExpressionInconnu:
                    std::cout << "Le fait n'est pas dans l'expression.";
                    break;

                case sysexp::modele::Erreurs::faitSymboliqueInconnu:
                    std::cout << "Le fait symbolique n'existe pas.";
                    break;

                default:
                    std::cout << "Code d'erreur inconnu.";
                    break;

            }
            std::cout << std::endl;

        }

    }

}
