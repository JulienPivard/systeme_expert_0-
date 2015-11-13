#include "jeton.hpp"
#include "fabriqueJeton.hpp"
#include "lexical.hpp"
#include "syntaxique.hpp"
#include <sstream>
#include <iostream>
#include <istream>
#include <fstream>

#include "BaseFait.hpp"

using namespace sysexp::builders;

void
representationJeton(std::istream & chaine) {
        const char* types[] = {"parentheseOuvrante", "parentheseFermante", "superieur", "inferieur",
                              "operateurPlus", "operateurMoins", "operateurMul", "operateurDiv",
                              "egal", "finExpression", "identificateur", "entier",
                              "si", "non", "et", "alors", "separateur", "inconnu", "finFichier",
                              "supEgal", "infEgal", "different", "faitBool", "faitSymb", "faitEnt"};
        Lexical lexical = Lexical(chaine);
        Jeton jeton = lexical.suivant();
        while(!jeton.estFinFichier()){
                sysexp::type::Type typeJeton = jeton.lireType();
                std::cout << types[typeJeton] << "(" << jeton.lireRepresentation() << ")" << std::endl;
                jeton = lexical.suivant();
        }
}

int
main(int argc, char* argv[] ){
    if( argc > 1 ){
        std::cout << "Usage "
            << argv[0]
            << std::endl;
    }
    if( argc != 1 ){
        std::cerr << "Trop d'argument, tartine de pus !"
            << std::endl;
        return EXIT_FAILURE;

    }
	//"/home/etudiants/20905973/Bureau/projet-c/src/lorraine.txt"
    //"/home/sandy/Documents/M1/C++/projet-c/src/lorraine.txt"
    std::ifstream chaine("/home/sandy/Documents/M1/C++/projet-c/src/lorraine.txt");
    //std::ifstream chaine("/home/etudiants/21001698/Master1/Parallellisme/Devoir/projet-c/src/lorraine.txt");
    //representationJeton(chaine);
    Lexical lexical = Lexical(chaine);
    Syntaxique syn(lexical);
    sysexp::modele::RegleAbstraite::PtrRegleAbstraite regle = syn.parser();
    sysexp::modele::RegleAbstraite::PtrRegleAbstraite regleTmp = regle;

    while( regleTmp != nullptr ){
        regleTmp->afficher();
        regleTmp = regleTmp->lireSuccesseur();
        std::cout << std::endl;
    }

    //sysexp::modele::BaseFait::PtrBaseFait base( new sysexp::modele::BaseFait() );
    //bool iterer;
    //do
    //{
    //    iterer = regle->iter( base );
    //} while( iterer );
    //base->afficher();

    return EXIT_SUCCESS;
}
