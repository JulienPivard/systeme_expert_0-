#include "BaseFait.hpp"

namespace sysexp
{
    namespace modele
    {

        void BaseFait::afficher() const
        {
            for( const std::pair< std::string, FaitAbstrait::PtrFaitAbstrait > & couple : baseFait_ )
            {

                FaitAbstrait::PtrFaitAbstrait faitAbstrait =  couple.second;
                std::cout << "Nom : " << faitAbstrait->lireNom();
                switch( faitAbstrait->type() )
                {

                    case TypeFait::faitBool:
                        {
                            const FaitBool* fait = static_cast< const FaitBool* >( faitAbstrait.get() );
                            std::cout << " valeur "
                                << std::boolalpha
                                << fait->lireValeur()
                                << std::endl;
                        }
                        break;

                    case TypeFait::faitEntier:
                        {
                            const FaitEntier* fait = static_cast< const FaitEntier* >( faitAbstrait.get() );
                            std::cout << " valeur "
                                << fait->lireValeur()
                                << std::endl;
                        }
                        break;

                    case TypeFait::faitSymbolique:
                        {
                            const FaitSymbolique* fait = static_cast< const FaitSymbolique* >( faitAbstrait.get() );
                            std::cout << " valeur "
                                << fait->lireValeur()
                                << std::endl;
                        }
                        break;

                    default:
                        std::cerr << "Le type du fait n'existe pas."
                            << std::endl;
                        throw ExceptionFaitInconnu();
                        break;

                }

            }
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
                if( faitDansBase->type() != fait->type() )
                {
                    throw ExceptionFaitDejaAjoute();
                }
                else        // Les faits sont de même type.
                {

                    switch( fait->type() )
                    {
                        case TypeFait::faitBool:
                        {

                            const FaitBool* ptrFait = static_cast< const FaitBool* >( fait.get() );
                            const FaitBool* ptrFaitDansBase = static_cast< const FaitBool* >( faitDansBase.get() );
                            if( ptrFaitDansBase->lireValeur() != ptrFait->lireValeur() )
                            {
                                throw ExceptionFaitDejaAjoute();
                            }

                        }
                        break;

                        case TypeFait::faitEntier:
                        {

                            const FaitEntier* ptrFait = static_cast< const FaitEntier* >( fait.get() );
                            const FaitEntier* ptrFaitDansBase = static_cast< const FaitEntier* >( faitDansBase.get() );
                            if( ptrFaitDansBase->lireValeur() != ptrFait->lireValeur() )
                            {
                                throw ExceptionFaitDejaAjoute();
                            }

                        }
                        break;

                        case TypeFait::faitSymbolique:
                        {

                            const FaitSymbolique* ptrFait = static_cast< const FaitSymbolique* >( fait.get() );
                            const FaitSymbolique* ptrFaitDansBase = static_cast< const FaitSymbolique* >( faitDansBase.get() );
                            if( ptrFaitDansBase->lireValeur() != ptrFait->lireValeur() )
                            {
                                throw ExceptionFaitDejaAjoute();
                            }

                        }
                        break;

                        default:
                            std::cerr << "Le type du fait n'existe pas !"
                                << std::endl;
                    }

                }

            }
            else
            {
                baseFait_.insert( std::pair<std::string, FaitAbstrait::PtrFaitAbstrait>( fait->lireNom(), fait ) );
            }
        }

    }
}
