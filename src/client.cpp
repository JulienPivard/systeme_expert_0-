/**
 * @mainpage
 *
 * Le système expert 0+ capable de comprendre la grammaire LORRAINE.
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
#include "parseException.hpp"

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

    std::cout << affichageTest ("Systeme expert 0+")
        << std::endl;

    // Contrôle du nombre d'argument sur la ligne de commande
    if( argc == 1 )
    {
        std::cout << "Usage : "
            << argv[0]
            << " nomFichierReglesLorraine."
            << std::endl;
        return EXIT_FAILURE;
    }
    else if( argc != 2 )
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
    sysexp::builders::lorraine::ConcreteBuilderLorraine::PtrConcreteBuilderLorraine monteurRegle( new sysexp::builders::lorraine::ConcreteBuilderLorraine( baseDeConnaissances ) );
    sysexp::builders::Directeur directeur = sysexp::builders::Directeur( monteurRegle );
    // Construction de la base de règles.
    try {
        directeur.construire();
    }
    catch (const sysexp::builders::lorraine::ParseException& e){
        std::cerr << "Erreur en parsant le fichier : " << argv[1] << std::endl;
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    // On récupère la base de règles généré par le monteur.
    sysexp::modele::RegleAbstraite::PtrRegleAbstraite baseDeRegles = directeur.livrer();

    // On initialise le moteur d'inférence avec la base de règles
    sysexp::modele::MoteurInference moteur = sysexp::modele::MoteurInference( baseDeRegles );
    try
    {
        moteur.analyserBaseRegles();
    }
    catch( const sysexp::modele::ExceptionDivParZero & e )
    {
        std::cerr << "Tentative de division par zéro ! "
            << std::endl;
        std::cerr << e.what()
            << std::endl;
        return EXIT_FAILURE;
    }
    catch( const sysexp::modele::ExceptionFaitDejaAjoute & e )
    {
        std::cerr << "Le fait à déjà été ajouté avec une autre valeur !"
            << std::endl;
        std::cerr << e.what()
            << std::endl;
        return EXIT_FAILURE;
    }
    catch( const sysexp::modele::ExceptionFaitInconnu & e )
    {
        std::cerr << "Le fait n'existe pas !"
            << std::endl;
        std::cerr << e.what()
            << std::endl;
        return EXIT_FAILURE;
    }

    // On affiche la base de fait une fois que le moteur à exécuté la base de règle.
    moteur.afficherBaseFaits();

    return EXIT_SUCCESS;

}
