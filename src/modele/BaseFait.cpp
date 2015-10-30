#include <cstdlib>
#include <iostream>
#include "BaseFait.hpp"
#include "FaitEntier.hpp"

namespace sysexp
{
    namespace modele
    {

        void BaseFait::afficher() const
        {
            for( const std::pair<std::string, std::shared_ptr<FaitAbstrait>> & couple : baseFait_ )
            {
                FaitAbstrait::PtrFaitAbstrait fait( couple.second );
                FaitEntier::PtrFaitEntier fait2 = std::dynamic_pointer_cast<FaitEntier>(fait);

                std::cout << couple.first
                    << " valeur "
                    << fait2->lireValeur()
                    << std::endl;
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
