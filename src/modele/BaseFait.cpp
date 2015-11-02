#include "BaseFait.hpp"

namespace sysexp
{
    namespace modele
    {

        void BaseFait::afficher() const
        {
            for( const std::pair<std::string, std::shared_ptr<FaitAbstrait>> & couple : baseFait_ )
            {

                FaitAbstrait::PtrFaitAbstrait faitAbstrait =  couple.second;
                std::cout << "Nom : " << faitAbstrait->lireNom();
                switch( faitAbstrait->type() )
                {

                    case TypeFait::faitBool:
                        {
                            const FaitBool* fait = static_cast<const FaitBool*>( faitAbstrait.get() );
                            std::cout << " valeur "
                                << fait->lireValeur()
                                << std::endl;
                        }
                        break;

                    case TypeFait::faitEntier:
                        {
                            const FaitEntier* fait = static_cast<const FaitEntier*>( faitAbstrait.get() );
                            std::cout << " valeur "
                                << fait->lireValeur()
                                << std::endl;
                        }
                        break;

                    case TypeFait::faitSymbolique:
                        {
                            const FaitSymbolique* fait = static_cast<const FaitSymbolique*>( faitAbstrait.get() );
                            std::cout << " valeur "
                                << fait->lireValeur()
                                << std::endl;
                        }
                        break;

                    default:
                        std::cout << "Le type du fait n'existe pas."
                            << std::endl;
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
            return baseFait_.find( nomFait )->second;
        }

        void
        BaseFait::ajouter( const FaitAbstrait::PtrFaitAbstrait & fait )
        {
            baseFait_.insert( std::pair<std::string, FaitAbstrait::PtrFaitAbstrait>( fait->lireNom(), fait ) );
        }

    }
}
