/**
 * @mainpage
 *
 * Le systeme expert 0+ capable de comprendre la grammaire LORRAINE.
 *
 * @author PIVARD Julien, CLECH Sandy
 */
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "BaseFait.hpp"
#include "FaitEntier.hpp"
#include "FaitAbstrait.hpp"
#include "fabriqueJeton.hpp"
#include "jeton.hpp"

using namespace sysexp::builders;
// using namespace sysexp::modele;
/**
 * Programme principal.
 *
 * @param[in] argc - le nombre d'arguments de la ligne de commande.
 * @param[in] argv - les arguments de la ligne de commandes.
 * @return @c EXIT_FAILURE en cas d'exécution réussie o @c EXIT_FAILURE sinon.
 */
int main( int argc, char* argv[] )
{

    // Controle du nombre d'argument sur la ligne de commande
    if( argc > 1 )
    {
        std::cout << "Usage "
            << argv[0]
            << std::endl;
    }
    if( argc != 1 )
    {
        std::cerr << "Trop d'argument, tartine de pus !"
            << std::endl;
        return EXIT_FAILURE;
    }

    /*
    // Cast de chaine dans un type précis.
    std::istringstream laChaine( argv[1] );
    int e ;
    laChaine >> e;

    // Vérification de la réussite du cast.
    if( laChaine && laChaine.eof() )
    {
        std::cout << argv[1]
            << std::endl;
        return EXIT_SUCCESS;
    }
    else
    {
        std::cerr << argv[1]
            << " Pas un entier."
            << std::endl;
        return EXIT_FAILURE;
    }


	// test de la base de fait

    sysexp::modele::BaseFait base;
    //sysexp::modele::FaitEntier fait = sysexp::modele::FaitEntier( "truc", 7 );
    //base.ajouter( fait );

    bool trouve = base.appartient( "bidule" );
    std::cout << "On a trouve bidule dans la base de fait : "
        << std::boolalpha
        << trouve
        << std::endl;
	// test sur les jetons (ça marche)
	Jeton parentheseOuvrante = FabriqueJeton::parentheseOuvrante();
	std::cout << std::boolalpha << parentheseOuvrante.estParentheseOuvrante()
            << std::endl;

    Jeton identificateur = FabriqueJeton::identificateur("titi");
    std::cout << std::boolalpha << identificateur.estIdentificateur()
            << std::endl;
    */

    //base.afficher();

    //sysexp::modele::FaitEntier fait = sysexp::modele::FaitEntier( "truc", 5 );
    //std::cout << "nom : "
    //<< fait.lireNom();
    //std::cout << " valeur : "
    //<< fait.lireValeur()
    //<< std::endl;

    //sysexp::modele::FaitAbstrait fait2 = fait;
    //sysexp::modele::FaitAbstrait * pfait2 = &fait2;
    //sysexp::modele::FaitEntier * fait3 = (sysexp::modele::FaitEntier *) pfait2;
    //std::cout << "nom : "
    //<< fait3->lireNom();
    //std::cout << " valeur : "
    //<< fait3->lireValeur()
    //<< std::endl;

    return EXIT_SUCCESS;

}
