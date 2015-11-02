#include <cstdlib>
#include <iostream>
#include <memory>

#include "BaseFait.hpp"
#include "FaitAbstrait.hpp"
#include "FaitEntier.hpp"
#include "FaitBool.hpp"
#include "FaitSymbolique.hpp"

namespace sysexp
{
    namespace modele
    {

        void BaseFait::afficher() const
        {
            for( const std::pair<std::string, std::shared_ptr<FaitAbstrait>> & couple : baseFait_ )
            {

                switch( couple.second.get()->type() )
                {

                    case TypeFait::faitBool:
                        //FaitBool* fait = static_cast<FaitBool*>( couple.second.get() );
                        break;

                    case TypeFait::faitEntier:
                        //FaitEntier* fait = static_cast<FaitEntier*>(  couple.second.get() );
                        break;

                    case TypeFait::faitSymbolique:
                        //FaitSymbolique* fait = static_cast<FaitSymbolique*>(   couple.second.get() );
                        break;

                    default:
                        std::cout << "Le type du fait n'existe pas."
                            << std::endl;
                    break;

                }

                std::cout << couple.first
                    << " valeur "
                    //<< fait2->lireValeur()
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
