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

#include "ValeurAbstraite.hpp"
#include "FeuilleConstante.hpp"
#include "FeuilleFait.hpp"
#include "OperateurAbstrait.hpp"
#include "OperateurPlus.hpp"
#include "OperateurMoins.hpp"
#include "OperateurMul.hpp"
#include "OperateurDiv.hpp"
#include "ExceptionDivParZero.hpp"
#include "VisiteurForme.hpp"
#include "FormeConclusionBoolTrue.hpp"

#include "fabriqueJeton.hpp"
#include "jeton.hpp"
#include "lexical.hpp"

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

    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    std::cout << affichageTest("Début des tests de BaseFait") << std::endl
        << std::endl;

	sysexp::modele::BaseFait base;
    {
        sysexp::modele::FaitEntier::PtrFaitEntier fait( new sysexp::modele::FaitEntier("machin", 5) );
        base.ajouter(fait);
    }

    {
        sysexp::modele::FaitEntier::PtrFaitEntier fait( new sysexp::modele::FaitEntier("bidule", 15) );
        base.ajouter(fait);
    }

    {
        sysexp::modele::FaitEntier::PtrFaitEntier fait( new sysexp::modele::FaitEntier("blabla", 9) );
        base.ajouter(fait);
    }

    {
        sysexp::modele::FaitBool::PtrFaitBool fait( new sysexp::modele::FaitBool("temaere", true) );
        base.ajouter(fait);
    }

    try
    {
        sysexp::modele::FaitEntier::PtrFaitEntier fait( new sysexp::modele::FaitEntier("bidule", 10) );
        base.ajouter(fait);
    }
    catch( sysexp::modele::ExceptionFaitDejaAjoute & e )
    {
        std::cerr << "Erreur la base de règle est incohérente."
            << std::endl;
    }

    {
        sysexp::modele::FaitSymbolique::PtrFaitSymbolique fait( new sysexp::modele::FaitSymbolique("cheval", "génial") );
        base.ajouter(fait);
    }

    std::cout << "================================"
        << std::endl;
    std::cout << "= Affichage de la base de fait ="
        << std::endl;
    std::cout << "================================"
        << std::endl;
    base.afficher();

    std::cout << std::endl;
    std::cout << "================================"
        << std::endl;
    std::cout << "=   Test de présence de fait   ="
        << std::endl;
    std::cout << "================================"
        << std::endl;

    bool trouve = base.appartient( "bidule" );
    std::cout << "\nOn a trouve bidule dans la base de fait : "
        << std::boolalpha
        << trouve
        << std::endl;

    std::cout << affichageTest("Fin des tests de BaseFait") << std::endl;
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    std::cout << affichageTest("Début des tests sur visiteur.") << std::endl
        << std::endl;

    sysexp::modele::BaseFait::PtrBaseFait base2( new sysexp::modele::BaseFait() );
    sysexp::modele::FormeConclusionBoolTrue conclusion = sysexp::modele::FormeConclusionBoolTrue( "truc" );
    sysexp::modele::VisiteurForme::PtrVisiteurForme visiteur( new sysexp::modele::VisiteurForme( base2 ) );
    conclusion.accept( visiteur );

    std::cout << "================================"
        << std::endl;
    std::cout << "= Affichage de la base de fait ="
        << std::endl;
    std::cout << "================================"
        << std::endl;
    base2->afficher();

    std::cout << std::endl;
    std::cout << affichageTest("Fin des tests sur visiteur.") << std::endl;
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    std::cout << affichageTest("Début des tests de ValeurAbstraite") << std::endl
        << std::endl;

    sysexp::modele::FeuilleConstante::PtrFeuilleConstante f1( new sysexp::modele::FeuilleConstante(3) );
    sysexp::modele::FeuilleConstante::PtrFeuilleConstante f2( new sysexp::modele::FeuilleConstante(2) );
    sysexp::modele::OperateurPlus::PtrOperateurPlus opplus( new sysexp::modele::OperateurPlus( f1, f2 ) );
    sysexp::modele::ValeurAbstraite::PtrValeur val(opplus);

    std::cout << "La valeur de "
        << f1->interpret( base )
        << " + "
        << f2->interpret( base )
        << " = "
        << val->interpret( base )
        << std::endl;

    sysexp::modele::FeuilleFait::PtrFeuilleFait f3( new sysexp::modele::FeuilleFait( "bidule" ) );
    sysexp::modele::FeuilleConstante::PtrFeuilleConstante f4( new sysexp::modele::FeuilleConstante(10) );
    sysexp::modele::OperateurMoins::PtrOperateurMoins opm( new sysexp::modele::OperateurMoins( f3, f4 ) );
    sysexp::modele::OperateurPlus::PtrOperateurPlus opp( new sysexp::modele::OperateurPlus( f1, opm ) );
    sysexp::modele::ValeurAbstraite::PtrValeur val2(opp);

    std::cout << "La valeur de "
        << f1->interpret( base )
        << " + ("
        << f3->interpret( base )
        << " - "
        << f4->interpret( base )
        << ") = "
        << val2->interpret( base )
        << std::endl;

    sysexp::modele::OperateurMul::PtrOperateurMul opmul( new sysexp::modele::OperateurMul( f1, f2 ) );
    sysexp::modele::ValeurAbstraite::PtrValeur val3(opmul);

    std::cout << "La valeur de "
        << f1->interpret( base )
        << " * "
        << f2->interpret( base )
        << " = "
        << val3->interpret( base )
        << std::endl;

    sysexp::modele::OperateurDiv::PtrOperateurDiv opd( new sysexp::modele::OperateurDiv( f4, f2 ) );
    sysexp::modele::ValeurAbstraite::PtrValeur val4(opd);

    std::cout << "La valeur de "
        << f4->interpret( base )
        << " / "
        << f2->interpret( base )
        << " = "
        << val4->interpret( base )
        << std::endl;

    sysexp::modele::FeuilleConstante::PtrFeuilleConstante f5( new sysexp::modele::FeuilleConstante(0) );
    sysexp::modele::OperateurDiv::PtrOperateurDiv opd2( new sysexp::modele::OperateurDiv( f2, f5 ) );
    sysexp::modele::ValeurAbstraite::PtrValeur val5(opd2);

    std::cout << "La valeur de "
        << f2->interpret( base )
        << " / "
        << f5->interpret( base )
        << " = ";

    try
    {
        std::cout << val5->interpret( base )
            << std::endl;
    }
    catch( sysexp::modele::ExceptionDivParZero & e )
    {
        std::cerr << "Erreur division par zéro."
            << std::endl;
    }

    std::cout << affichageTest("Fin des tests de ValeurAbstraite") << std::endl
        << std::endl;
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

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
