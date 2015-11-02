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
#include <memory>
#include <exception>

#include "BaseFait.hpp"
#include "FaitEntier.hpp"
#include "FaitBool.hpp"
#include "FaitAbstrait.hpp"
#include "fabriqueJeton.hpp"
#include "jeton.hpp"
#include "FeuilleConstante.hpp"
#include "ValeurAbstraite.hpp"
#include "lexical.hpp"

using namespace sysexp::builders;
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
    */

	sysexp::modele::BaseFait base;
    sysexp::modele::FaitEntier::PtrFaitEntier fait1( new sysexp::modele::FaitEntier("machin", 5) );
    base.ajouter(fait1);

    sysexp::modele::FaitEntier::PtrFaitEntier fait2( new sysexp::modele::FaitEntier("bidule", 15) );
    base.ajouter(fait2);

    sysexp::modele::FaitBool::PtrFaitBool fait3( new sysexp::modele::FaitBool("blabla", true) );
    base.ajouter(fait3);

    try
    {
        sysexp::modele::FaitEntier::PtrFaitEntier fait4( new sysexp::modele::FaitEntier("blabla", 9) );
        base.ajouter(fait4);
    }
    catch(std::exception & e)
    {
        std::cerr << "Erreur "
            << std::endl;
    }

    sysexp::modele::FaitSymbolique::PtrFaitSymbolique fait5( new sysexp::modele::FaitSymbolique("cheval", "genial") );
    base.ajouter(fait5);

    std::cout << "================================"
        << std::endl;
    std::cout << "= Affichage de la base de fait ="
        << std::endl;
    std::cout << "================================"
        << std::endl;
    base.afficher();

    std::cout << std::endl
        << std::endl;
    std::cout << "================================"
        << std::endl;
    std::cout << "= Test de présence de fait ="
        << std::endl;
    std::cout << "================================"
        << std::endl;
    bool trouve = base.appartient( "bidule" );
    std::cout << "\nOn a trouve bidule dans la base de fait : "
        << std::boolalpha
        << trouve
        << std::endl;

    /*
	// test sur les jetons (ça marche)
	Jeton parentheseOuvrante = FabriqueJeton::parentheseOuvrante();
	std::cout << std::boolalpha << parentheseOuvrante.estParentheseOuvrante()
            << std::endl;

    Jeton identificateur = FabriqueJeton::identificateur("titi");
    std::cout << std::boolalpha << identificateur.estIdentificateur()
            << std::endl;
     * */

    /*
	Lexical lorraine("/home/etudiants/20905973/Bureau/projet-c/src/lorraine.txt");
	Jeton machin = lorraine.suivant();
	std::cout << std::boolalpha
	<< machin.estFinFichier() << "\n"
	<< machin.estSi()
	<< std::endl;
     * */

    return EXIT_SUCCESS;

}
