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

#include "directeur.hpp"
#include "concreteBuilderLorraine.hpp"

#include "MoteurInference.hpp"

/*
 * Fonction d'affichage de séparateur de zone,
 * pour faciliter la lecture sur la sortie standard.
 * */
std::string affichageTest( std::string nomZone )
{

    if( nomZone.size() % 2 == 1 )
    {
        nomZone += ' ';
    }

    std::string ligne =  "==========================================================================================";
    int nbEspaceBlanc = ligne.size() - nomZone.size() - 2;
    std::string blanc;

    for( int i = 0; i < nbEspaceBlanc / 2; i++ )
    {
        blanc += ' ';
    }

    return ligne + "\n=" + blanc + nomZone + blanc + "=\n" + ligne;

}

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
    if( argc == 1 )
    {
        std::cout << "Usage : "
            << argv[0]
            << " nomFichierReglesLorraine."
            << std::endl;
    }
    if( argc != 2 )
    {
        std::cerr << "Trop d'argument, un seul attendu."
            << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream baseDeConnaissances( argv[1] );
    if( ! baseDeConnaissances )
    {
        std::cerr << "Impossible d'ouvrir le fichier [ "
            << argv[1]
            << " ]"
            << std::endl;
        return EXIT_FAILURE;
    }

    // Mise en place du monteur de règles.
    sysexp::builders::ConcreteBuilderLorraine::PtrConcreteBuilderLorraine monteurRegle( new sysexp::builders::ConcreteBuilderLorraine( baseDeConnaissances ) );
    sysexp::builders::Directeur directeur = sysexp::builders::Directeur( monteurRegle );
    // Construction de la base de règles.
    directeur.construire();

    sysexp::modele::RegleAbstraite::PtrRegleAbstraite baseDeRegles = directeur.livrer();

    sysexp::modele::MoteurInference moteur = sysexp::modele::MoteurInference( baseDeRegles );
    moteur.analyserBaseRegles();
    std::cout << std::endl;
    std::cout << "========== Affichage de la base de fait. =========="
        << std::endl
        << std::endl;
    moteur.afficherBaseFaits();

    return EXIT_SUCCESS;

}
