#include <cstdlib>
#include <iostream>
#include "BaseFait.hpp"

namespace sysexp
{
    namespace modele
    {

        void BaseFait::afficher() const
        {
            for( const std::pair<std::string, Fait> & couple : baseFait_ )
            {
                Fait valeur = couple.second;

                std::cout << couple.first
                    << " valeur "
                    //<< couple.second
                    << std::endl;
            }
        }

        bool
        BaseFait::appartient( const std::string & nomFait ) const
        {
            return baseFait_.find( nomFait ) != baseFait_.end();
        }

        const Fait &
        BaseFait::trouver( const std::string & nomFait ) const
        {
            return baseFait_.find( nomFait )->second;
        }

        void
        BaseFait::ajouter( const Fait & fait )
        {
            baseFait_.insert( std::pair<std::string, Fait>( fait.lireNom(), fait ) );
        }

    }
}
