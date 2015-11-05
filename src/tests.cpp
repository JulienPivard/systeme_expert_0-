#include "jeton.hpp"
#include "fabriqueJeton.hpp"
#include "lexical.hpp"
#include <sstream>
#include <istream>
#include <fstream>
#include <iostream>
using namespace sysexp::builders;

sysexp::type::Type
representationJeton(std::istream & chaine) {
	Lexical lexical = Lexical(chaine);
	Jeton jeton = lexical.suivant();
	return jeton.lireType();
}

int
main(int argc, char* argv[] ){
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
	std::istringstream chaine("vache");
	std::cout << representationJeton(chaine) << std::endl;
	return EXIT_SUCCESS;
}

