#include "BaseFait.hpp"

namespace sysexp
{

    namespace modele
    {

        void BaseFait::afficher() const
        {

            std::cout << std::endl
                << "========== Affichage de la base de fait. =========="
                << std::endl << std::endl;

            const std::string fleche =  "└─────────  ";
            //const std::string fleche =  "┗━━━━━━━━━  ";

            for( const std::pair< std::string, FaitAbstrait::PtrFaitAbstrait > & couple : baseFait_ )
            {

                FaitAbstrait::PtrFaitAbstrait faitAbstrait =  couple.second;

                switch( faitAbstrait->lireType() )
                {

                    case TypeFait::faitBool:
                        {
                            const FaitBool* fait = static_cast< const FaitBool* >( faitAbstrait.get() );
                            std::cout << "Booléen "
                                << std::endl
                                << fleche;
                            if( ! fait->lireValeur() )
                            {
                                std::cout << "Non ";
                            }
                            std::cout << faitAbstrait->lireNom();
                        }
                        break;

                    case TypeFait::faitEntier:
                        {
                            const FaitEntier* fait = static_cast< const FaitEntier* >( faitAbstrait.get() );
                            std::cout << "Entier "
                                << std::endl
                                << fleche
                                << faitAbstrait->lireNom()
                                << " = "
                                << fait->lireValeur();
                        }
                        break;

                    case TypeFait::faitSymbolique:
                        {
                            const FaitSymbolique* fait = static_cast< const FaitSymbolique* >( faitAbstrait.get() );
                            std::cout << "Symbolique"
                                << std::endl
                                << fleche
                                << faitAbstrait->lireNom()
                                << " = "
                                << fait->lireValeur();
                        }
                        break;

                    default:
                        std::cerr << "Le type du fait n'existe pas.";
                        throw ExceptionFaitInconnu();
                        break;

                }
                std::cout << std::endl;

            }

            std::cout << std::endl
                << "======= Fin d'affichage de la base de fait. ======="
                << std::endl << std::endl;

        }

        bool
        BaseFait::appartient( const std::string & nomFait ) const
        {
            return baseFait_.find( nomFait ) != baseFait_.end();
        }

        const FaitAbstrait::PtrFaitAbstrait &
        BaseFait::trouver( const std::string & nomFait ) const
        {
            if( ! appartient( nomFait ) )
            {
                throw ExceptionFaitInconnu();
            }
            return baseFait_.find( nomFait )->second;
        }

        void
        BaseFait::ajouter( const FaitAbstrait::PtrFaitAbstrait & fait )
        {
            if( appartient( fait->lireNom() ) )
            {

                // On récupère le fait qui existe déjà dans la base avec ce nom.
                FaitAbstrait::PtrFaitAbstrait faitDansBase( trouver( fait->lireNom() ) );
                // Ici le fait de même nom n'est pas de même type.
                // N'est présent que par soucis d'exhaustivité, n'est normalement jamais déclenché.
                if( faitDansBase->lireType() != fait->lireType() )
                {
                    throw ExceptionFaitDejaAjoute( "Le fait [ " + fait->lireNom() + " ] existe déjà avec un autre type." );
                }
                else        // Les faits sont de même type.
                {

                    switch( fait->lireType() )
                    {
                        case TypeFait::faitBool:
                        {

                            const FaitBool* ptrFait = static_cast< const FaitBool* >( fait.get() );
                            const FaitBool* ptrFaitDansBase = static_cast< const FaitBool* >( faitDansBase.get() );
                            if( ptrFaitDansBase->lireValeur() != ptrFait->lireValeur() )
                            {
                                throw ExceptionFaitDejaAjoute( "Le fait [ "
                                        + ptrFaitDansBase->lireNom()
                                        + " ] existe déjà dans la base avec la valeur [ "
                                        + ( ptrFaitDansBase->lireValeur() ? "vrais" : "faux" )
                                        + " ] dans la base de fait."
                                        );
                            }

                        }
                        break;

                        case TypeFait::faitEntier:
                        {

                            const FaitEntier* ptrFait = static_cast< const FaitEntier* >( fait.get() );
                            const FaitEntier* ptrFaitDansBase = static_cast< const FaitEntier* >( faitDansBase.get() );
                            if( ptrFaitDansBase->lireValeur() != ptrFait->lireValeur() )
                            {
                                throw ExceptionFaitDejaAjoute( "Le fait [ "
                                        + ptrFaitDansBase->lireNom()
                                        + " ] existe déjà dans la base avec la valeur [ "
                                        + std::to_string( ptrFaitDansBase->lireValeur() )
                                        + " ] dans la base de fait."
                                        );
                            }

                        }
                        break;

                        case TypeFait::faitSymbolique:
                        {

                            const FaitSymbolique* ptrFait = static_cast< const FaitSymbolique* >( fait.get() );
                            const FaitSymbolique* ptrFaitDansBase = static_cast< const FaitSymbolique* >( faitDansBase.get() );
                            if( ptrFaitDansBase->lireValeur() != ptrFait->lireValeur() )
                            {
                                throw ExceptionFaitDejaAjoute( "Le fait [ "
                                        + ptrFaitDansBase->lireNom()
                                        + " ] existe déjà dans la base avec la valeur [ "
                                        + ptrFaitDansBase->lireValeur()
                                        + " ] dans la base de fait."
                                        );
                            }

                        }
                        break;

                        default:
                            std::cerr << "Le type du fait n'existe pas !"
                                << std::endl;
                        break;
                    }

                }

            }
            else
            {
                // Le fait n'existe pas déjà dans la base de fait.
                baseFait_.insert( std::pair<std::string, FaitAbstrait::PtrFaitAbstrait>( fait->lireNom(), fait ) );
            }
        }

    }

}
