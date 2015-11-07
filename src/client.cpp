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

    sysexp::modele::FeuilleConstante::PtrFeuilleConstante f1( new sysexp::modele::FeuilleConstante(3) );
    sysexp::modele::FeuilleConstante::PtrFeuilleConstante f2( new sysexp::modele::FeuilleConstante(2) );
    sysexp::modele::OperateurPlus::PtrOperateurPlus opplus( new sysexp::modele::OperateurPlus( f1, f2 ) );
    sysexp::modele::ValeurAbstraite::PtrValeur val(opplus);

    sysexp::modele::OperateurMul::PtrOperateurMul opm1( new sysexp::modele::OperateurMul( opplus, f1 ) );
    sysexp::modele::ValeurAbstraite::PtrValeur val1(opm1);

    sysexp::modele::FeuilleFait::PtrFeuilleFait f3( new sysexp::modele::FeuilleFait( "bidule" ) );
    sysexp::modele::FeuilleConstante::PtrFeuilleConstante f4( new sysexp::modele::FeuilleConstante(10) );
    sysexp::modele::OperateurMoins::PtrOperateurMoins opm( new sysexp::modele::OperateurMoins( f3, f4 ) );
    sysexp::modele::OperateurPlus::PtrOperateurPlus opp( new sysexp::modele::OperateurPlus( f1, opm ) );
    sysexp::modele::ValeurAbstraite::PtrValeur val2(opp);

    sysexp::modele::OperateurMul::PtrOperateurMul opmul( new sysexp::modele::OperateurMul( f1, f2 ) );
    sysexp::modele::ValeurAbstraite::PtrValeur val3(opmul);

    sysexp::modele::OperateurDiv::PtrOperateurDiv opd( new sysexp::modele::OperateurDiv( f4, f2 ) );
    sysexp::modele::ValeurAbstraite::PtrValeur val4(opd);

    sysexp::modele::BaseFait::PtrBaseFait base( new sysexp::modele::BaseFait() );

    {
        sysexp::modele::FormeConclusionBoolTrue conclusion = sysexp::modele::FormeConclusionBoolTrue( "truc" );
        sysexp::modele::VisiteurForme::PtrVisiteurForme visiteur( new sysexp::modele::VisiteurForme( base ) );
        conclusion.accept( visiteur );

        std::cout << std::endl
            << "Règle "
            << conclusion.lireNom()
            << std::endl;
        std::cout << "La prémisse à été déclenchée : "
            << std::boolalpha
            << visiteur->getPremisseVerifiee()
            << std::endl;
        std::cout << "La conclusion à été déclenchée : "
            << std::boolalpha
            << visiteur->getConclusionDeclenchee()
            << std::endl;
        std::cout << "Erreur d'exécution : ";

        switch( visiteur->getCodeErreurExecution() )
        {

            case sysexp::modele::Erreurs::toutVaBien:
                std::cout << "pas d'erreur.";
                break;

            case sysexp::modele::Erreurs::incoherenceFait:
                std::cout << "erreur la base est incohérente.";
                break;

            case sysexp::modele::Erreurs::divParZero:
                std::cout << "erreur division par zéro.";
                break;

            case sysexp::modele::Erreurs::faitInconnu:
                std::cout << "erreur le fait n'existe pas dans l'expression.";
                break;

            default:
                std::cout << "code d'erreur inconnu.";
                break;

        }
        std::cout << std::endl;
    }

    {
        sysexp::modele::FormeConclusionBoolFalse conclusion = sysexp::modele::FormeConclusionBoolFalse( "machin" );
        sysexp::modele::VisiteurForme::PtrVisiteurForme visiteur( new sysexp::modele::VisiteurForme( base ) );
        conclusion.accept( visiteur );

        std::cout << std::endl
            << "Règle "
            << conclusion.lireNom()
            << std::endl;
        std::cout << "La prémisse à été déclenchée : "
            << std::boolalpha
            << visiteur->getPremisseVerifiee()
            << std::endl;
        std::cout << "La conclusion à été déclenchée : "
            << std::boolalpha
            << visiteur->getConclusionDeclenchee()
            << std::endl;
        std::cout << "Erreur d'exécution : ";

        switch( visiteur->getCodeErreurExecution() )
        {

            case sysexp::modele::Erreurs::toutVaBien:
                std::cout << "pas d'erreur.";
                break;

            case sysexp::modele::Erreurs::incoherenceFait:
                std::cout << "erreur la base est incohérente.";
                break;

            case sysexp::modele::Erreurs::divParZero:
                std::cout << "erreur division par zéro.";
                break;

            case sysexp::modele::Erreurs::faitInconnu:
                std::cout << "erreur le fait n'existe pas dans l'expression.";
                break;

            default:
                std::cout << "code d'erreur inconnu.";
                break;

        }
        std::cout << std::endl;
    }

    {
        sysexp::modele::FormeConclusionEntierExpression conclusion = sysexp::modele::FormeConclusionEntierExpression( "nepasafficher", val1 );
        sysexp::modele::VisiteurForme::PtrVisiteurForme visiteur( new sysexp::modele::VisiteurForme( base ) );
        conclusion.accept( visiteur );

        std::cout << std::endl
            << "Règle "
            << conclusion.lireNom()
            << std::endl;
        std::cout << "La prémisse à été déclenchée : "
            << std::boolalpha
            << visiteur->getPremisseVerifiee()
            << std::endl;
        std::cout << "La conclusion à été déclenchée : "
            << std::boolalpha
            << visiteur->getConclusionDeclenchee()
            << std::endl;
        std::cout << "Erreur d'exécution : ";

        switch( visiteur->getCodeErreurExecution() )
        {

            case sysexp::modele::Erreurs::toutVaBien:
                std::cout << "pas d'erreur.";
                break;

            case sysexp::modele::Erreurs::incoherenceFait:
                std::cout << "erreur la base est incohérente.";
                break;

            case sysexp::modele::Erreurs::divParZero:
                std::cout << "erreur division par zéro.";
                break;

            case sysexp::modele::Erreurs::faitInconnu:
                std::cout << "erreur le fait n'existe pas dans l'expression.";
                break;

            default:
                std::cout << "code d'erreur inconnu.";
                break;

        }
        std::cout << std::endl;
    }

    {
        sysexp::modele::FormeConclusionEntierExpression conclusion = sysexp::modele::FormeConclusionEntierExpression( "soustraction", val2 );
        sysexp::modele::VisiteurForme::PtrVisiteurForme visiteur( new sysexp::modele::VisiteurForme( base ) );
        conclusion.accept( visiteur );

        std::cout << std::endl
            << "Règle "
            << conclusion.lireNom()
            << std::endl;
        std::cout << "La prémisse à été déclenchée : "
            << std::boolalpha
            << visiteur->getPremisseVerifiee()
            << std::endl;
        std::cout << "La conclusion à été déclenchée : "
            << std::boolalpha
            << visiteur->getConclusionDeclenchee()
            << std::endl;
        std::cout << "Erreur d'exécution : ";

        switch( visiteur->getCodeErreurExecution() )
        {

            case sysexp::modele::Erreurs::toutVaBien:
                std::cout << "pas d'erreur.";
                break;

            case sysexp::modele::Erreurs::incoherenceFait:
                std::cout << "erreur la base est incohérente.";
                break;

            case sysexp::modele::Erreurs::divParZero:
                std::cout << "erreur division par zéro.";
                break;

            case sysexp::modele::Erreurs::faitInconnu:
                std::cout << "erreur le fait n'existe pas dans l'expression.";
                break;

            default:
                std::cout << "code d'erreur inconnu.";
                break;

        }
        std::cout << std::endl;
    }

    {
        sysexp::modele::FormeConclusionEntierFait conclusion = sysexp::modele::FormeConclusionEntierFait( "blabla", "bidule" );
        sysexp::modele::VisiteurForme::PtrVisiteurForme visiteur( new sysexp::modele::VisiteurForme( base ) );
        conclusion.accept( visiteur );

        std::cout << std::endl
            << "Règle "
            << conclusion.lireNom()
            << std::endl;
        std::cout << "La prémisse à été déclenchée : "
            << std::boolalpha
            << visiteur->getPremisseVerifiee()
            << std::endl;
        std::cout << "La conclusion à été déclenchée : "
            << std::boolalpha
            << visiteur->getConclusionDeclenchee()
            << std::endl;
        std::cout << "Erreur d'exécution : ";

        switch( visiteur->getCodeErreurExecution() )
        {

            case sysexp::modele::Erreurs::toutVaBien:
                std::cout << "pas d'erreur.";
                break;

            case sysexp::modele::Erreurs::incoherenceFait:
                std::cout << "erreur la base est incohérente.";
                break;

            case sysexp::modele::Erreurs::divParZero:
                std::cout << "erreur division par zéro.";
                break;

            case sysexp::modele::Erreurs::faitInconnu:
                std::cout << "erreur le fait n'existe pas dans l'expression.";
                break;

            default:
                std::cout << "code d'erreur inconnu.";
                break;

        }
        std::cout << std::endl;
    }

    {
        sysexp::modele::FormeConclusionSymboliqueConstante conclusion = sysexp::modele::FormeConclusionSymboliqueConstante( "cheval", "génial" );
        sysexp::modele::VisiteurForme::PtrVisiteurForme visiteur( new sysexp::modele::VisiteurForme( base ) );
        conclusion.accept( visiteur );

        std::cout << std::endl
            << "Règle "
            << conclusion.lireNom()
            << std::endl;
        std::cout << "La prémisse à été déclenchée : "
            << std::boolalpha
            << visiteur->getPremisseVerifiee()
            << std::endl;
        std::cout << "La conclusion à été déclenchée : "
            << std::boolalpha
            << visiteur->getConclusionDeclenchee()
            << std::endl;
        std::cout << "Erreur d'exécution : ";

        switch( visiteur->getCodeErreurExecution() )
        {

            case sysexp::modele::Erreurs::toutVaBien:
                std::cout << "pas d'erreur.";
                break;

            case sysexp::modele::Erreurs::incoherenceFait:
                std::cout << "erreur la base est incohérente.";
                break;

            case sysexp::modele::Erreurs::divParZero:
                std::cout << "erreur division par zéro.";
                break;

            case sysexp::modele::Erreurs::faitInconnu:
                std::cout << "erreur le fait n'existe pas dans l'expression.";
                break;

            default:
                std::cout << "code d'erreur inconnu.";
                break;

        }
        std::cout << std::endl;
    }

    {
        sysexp::modele::FormeConclusionSymboliqueFait conclusion = sysexp::modele::FormeConclusionSymboliqueFait( "joker", "cheval" );
        sysexp::modele::VisiteurForme::PtrVisiteurForme visiteur( new sysexp::modele::VisiteurForme( base ) );
        conclusion.accept( visiteur );

        std::cout << std::endl
            << "Règle "
            << conclusion.lireNom()
            << std::endl;
        std::cout << "La prémisse à été déclenchée : "
            << std::boolalpha
            << visiteur->getPremisseVerifiee()
            << std::endl;
        std::cout << "La conclusion à été déclenchée : "
            << std::boolalpha
            << visiteur->getConclusionDeclenchee()
            << std::endl;
        std::cout << "Erreur d'exécution : ";

        switch( visiteur->getCodeErreurExecution() )
        {

            case sysexp::modele::Erreurs::toutVaBien:
                std::cout << "pas d'erreur.";
                break;

            case sysexp::modele::Erreurs::incoherenceFait:
                std::cout << "erreur la base est incohérente.";
                break;

            case sysexp::modele::Erreurs::divParZero:
                std::cout << "erreur division par zéro.";
                break;

            case sysexp::modele::Erreurs::faitInconnu:
                std::cout << "erreur le fait n'existe pas dans l'expression.";
                break;

            default:
                std::cout << "code d'erreur inconnu.";
                break;

        }
        std::cout << std::endl;
    }

    std::cout << "================================"
        << std::endl;
    std::cout << "= Affichage de la base de fait ="
        << std::endl;
    std::cout << "================================"
        << std::endl;
    base->afficher();

    std::cout << std::endl;
    std::cout << affichageTest("Fin des tests sur visiteur.") << std::endl;

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
