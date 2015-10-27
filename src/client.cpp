#include <cstdlib>

#include <cstdlib>
// Pour avoir accès aux entrées sorties des flux.
#include <iostream>
// istringstream pour lire en entrée une chaine.
// ostringstream pour
#include <sstream>

// Si on veut ne pas avoir à taper std::
// peut être mis dans un bloc
//using namespace std;

int main( int argc, char* argv[] )
{

    // Controle du nombre d'argument sur la ligne de commande
    if( argc == 1 )
    {
        std::cout << "Usage "
            << argv[0]
            << " entier"
            << std::endl;
    }
    if( argc != 2 )
    {
        std::cerr << "Trop d'argument, tartine de pus !"
            << std::endl;
        return EXIT_FAILURE;
    }

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

    return EXIT_SUCCESS;

}
