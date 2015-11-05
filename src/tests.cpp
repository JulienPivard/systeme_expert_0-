#include "jeton.hpp"
#include "fabriqueJeton.hpp"
#include "lexical.hpp"
#include "gtest/gtest.h"
#include <sstream>
#include <iostream>
using namespace sysexp::builders;
#include "jeton.hpp"

#include "fabriqueJeton.hpp"

#include "lexical.hpp"

#include <sstream>

#include <istream>

#include <fstream>

#include <iostream>

using namespace sysexp::builders;

void
representationJeton(std::istream & chaine) {
        const char* types[] = {"parentheseOuvrante", "parentheseFermante", "superieur", "inferieur",
                              "operateurPlus", "operateurMoins", "operateurMul", "operateurDiv",
                              "egal", "finExpression", "identificateur", "entier",
                              "si", "non", "et", "alors", "separateur", "inconnu", "finFichier"};
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
        std::istringstream chaine("si(bite et)alors , non  +  / = *  < > - 4; ?!_");
        representationJeton(chaine);
        return EXIT_SUCCESS;
}
