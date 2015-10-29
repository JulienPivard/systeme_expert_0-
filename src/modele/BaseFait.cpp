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
            for( const std::pair<std::string, FaitAbstrait> & couple : baseFait_ )
            {
                FaitAbstrait valeur = couple.second;
                FaitAbstrait * pValeur = &valeur;
                FaitEntier *fait = dynamic_cast<FaitEntier *>( pValeur );

                std::cout << couple.first
                    << " valeur "
                    << fait->lireValeur()
                    << std::endl;
            }
        }

        bool
        BaseFait::appartient( const std::string & nomFait ) const
        {
            return baseFait_.find( nomFait ) != baseFait_.end();
        }

        const FaitAbstrait &
        BaseFait::trouver( const std::string & nomFait ) const
        {
            return baseFait_.find( nomFait )->second;
        }

        void
        BaseFait::ajouter( const FaitAbstrait & fait )
        {
            baseFait_.insert( std::pair<std::string, FaitAbstrait>( fait.lireNom(), fait ) );
        }

    }
}
