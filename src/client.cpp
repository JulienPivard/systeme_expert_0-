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
#include "ExceptionFaitDejaAjoute.hpp"
#include "ExceptionFaitInconnu.hpp"

#include "VisiteurForme.hpp"
#include "FormeConclusionBoolTrue.hpp"
#include "FormeConclusionBoolFalse.hpp"
#include "FormeConclusionEntierExpression.hpp"
#include "FormeConclusionEntierFait.hpp"
#include "FormeConclusionSymboliqueConstante.hpp"
#include "FormeConclusionSymboliqueFait.hpp"

#include "RegleSansPremisse.hpp"

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
    std::cout << affichageTest("Début des tests sur visiteur et règles sans prémisses.") << std::endl
        << std::endl;

    sysexp::modele::FeuilleConstante::PtrFeuilleConstante f1( new sysexp::modele::FeuilleConstante(3) );
    sysexp::modele::FeuilleConstante::PtrFeuilleConstante f2( new sysexp::modele::FeuilleConstante(2) );
    sysexp::modele::OperateurPlus::PtrOperateurPlus opplus( new sysexp::modele::OperateurPlus( f1, f2 ) );
    sysexp::modele::ValeurAbstraite::PtrValeur val( opplus );

    sysexp::modele::OperateurMul::PtrOperateurMul opm1( new sysexp::modele::OperateurMul( opplus, f1 ) );
    sysexp::modele::ValeurAbstraite::PtrValeur val1( opm1 );

    sysexp::modele::FeuilleFait::PtrFeuilleFait f3( new sysexp::modele::FeuilleFait( "bidule" ) );
    sysexp::modele::FeuilleConstante::PtrFeuilleConstante f4( new sysexp::modele::FeuilleConstante(10) );
    sysexp::modele::OperateurMoins::PtrOperateurMoins opm( new sysexp::modele::OperateurMoins( f3, f4 ) );
    sysexp::modele::OperateurPlus::PtrOperateurPlus opp( new sysexp::modele::OperateurPlus( f1, opm ) );
    sysexp::modele::ValeurAbstraite::PtrValeur val2( opp );

    sysexp::modele::OperateurMul::PtrOperateurMul opmul( new sysexp::modele::OperateurMul( f1, f2 ) );
    sysexp::modele::ValeurAbstraite::PtrValeur val3( opmul );

    sysexp::modele::OperateurDiv::PtrOperateurDiv opd( new sysexp::modele::OperateurDiv( f4, f2 ) );
    sysexp::modele::ValeurAbstraite::PtrValeur val4( opd );

    sysexp::modele::FeuilleConstante::PtrFeuilleConstante f5( new sysexp::modele::FeuilleConstante(0) );
    sysexp::modele::OperateurDiv::PtrOperateurDiv opd0( new sysexp::modele::OperateurDiv( f4, f5 ) );
    sysexp::modele::ValeurAbstraite::PtrValeur val5( opd0 );

    sysexp::modele::BaseFait::PtrBaseFait base( new sysexp::modele::BaseFait() );

    std::cout << std::endl;
    std::cout << "================================"
        << std::endl;
    std::cout << "= Affichage de la base de fait ="
        << std::endl;
    std::cout << "================================"
        << std::endl;
    base->afficher();
    std::cout << std::endl;

    sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion7( new sysexp::modele::FormeConclusionSymboliqueFait( "jokey", "cheval" ) );
    sysexp::modele::RegleAbstraite::PtrRegleAbstraite regle7( new sysexp::modele::RegleSansPremisse( 7, conclusion7 ) );

    sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion6( new sysexp::modele::FormeConclusionSymboliqueConstante( "cheval", "génial" ) );
    sysexp::modele::RegleAbstraite::PtrRegleAbstraite regle6( new sysexp::modele::RegleSansPremisse( 6, conclusion6 ) );
    regle6->ajouterSuccesseur( regle7 );

    sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion5( new sysexp::modele::FormeConclusionEntierFait( "reprendValDevriaetrebidul", "devraisetrebidul" ) );
    sysexp::modele::RegleAbstraite::PtrRegleAbstraite regle5( new sysexp::modele::RegleSansPremisse( 5, conclusion5 ) );
    regle5->ajouterSuccesseur( regle6 );

    sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion4( new sysexp::modele::FormeConclusionEntierExpression( "nepasafficher", val2 ) );
    sysexp::modele::RegleAbstraite::PtrRegleAbstraite regle4( new sysexp::modele::RegleSansPremisse( 4, conclusion4 ) );
    regle4->ajouterSuccesseur( regle5 );

    sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion3( new sysexp::modele::FormeConclusionEntierExpression( "division", opd ) );
    sysexp::modele::RegleAbstraite::PtrRegleAbstraite regle3( new sysexp::modele::RegleSansPremisse( 3, conclusion3 ) );
    regle3->ajouterSuccesseur( regle4 );

    sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion2( new sysexp::modele::FormeConclusionEntierExpression( "devraisetrebidul", val1 ) );
    sysexp::modele::RegleAbstraite::PtrRegleAbstraite regle2( new sysexp::modele::RegleSansPremisse( 2, conclusion2 ) );
    regle2->ajouterSuccesseur( regle3 );

    sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion1( new sysexp::modele::FormeConclusionBoolFalse( "trucFaux" ) );
    sysexp::modele::RegleAbstraite::PtrRegleAbstraite regle1( new sysexp::modele::RegleSansPremisse( 1, conclusion1 ) );
    regle1->ajouterSuccesseur( regle2 );

    sysexp::modele::FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion conclusion( new sysexp::modele::FormeConclusionBoolTrue( "trucVrais" ) );
    sysexp::modele::RegleSansPremisse::PtrRegleAbstraite regle( new sysexp::modele::RegleSansPremisse( 0, conclusion ) );
    regle->ajouterSuccesseur( regle1 );
    bool resultat = regle->iter( base );
    std::cout << std::endl
        << "Au moins une règle a été déclenchée : "
        << std::boolalpha
        << resultat
        << std::endl;

    std::cout << std::endl;
    std::cout << "================================"
        << std::endl;
    std::cout << "= Affichage de la base de fait ="
        << std::endl;
    std::cout << "================================"
        << std::endl;
    base->afficher();

    std::cout << std::endl;
    std::cout << affichageTest("Fin des tests sur visiteur et règle sans prémisse.") << std::endl;
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%ù
    std::cout << affichageTest("Début des tests sur les signes.") << std::endl;

    int a = 5, b = 4;
    std::equal_to<int> c;
    std::cout << "Test de == :\n"
        << a
        << " == "
        << b
        << " : "
        << c( a, b )
        << std::endl;

    std::cout << affichageTest("Fin des tests sur les signes.") << std::endl;

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
