# Version de cmake demandée.
CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )

# Chemin des répertoires contenant les fichiers entêtes.
INCLUDE_DIRECTORIES(
    src/include/modele
    src/include/builders
   )

# Chemin du répertoire contenant les binaires.
SET ( EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

# Option du compilateur pour supporter C++ 2011.
SET( CMAKE_CXX_FLAGS "-std=c++11")

# Création des exécutables.
ADD_EXECUTABLE( client
    src/client.cpp
    src/modele/FaitAbstrait.cpp
    src/modele/FaitBool.cpp
    src/modele/FaitSymbolique.cpp
    src/modele/FaitEntier.cpp
    src/modele/BaseFait.cpp
    src/modele/FeuilleConstante.cpp
    src/modele/FeuilleFait.cpp
    src/modele/VisiteurFormesAbstrait.cpp
    src/builders/jeton.cpp
    src/builders/fabriqueJeton.cpp
    src/builders/lexical.cpp
    )

# Faire parler le make.
set( CMAKE_VERBOSE_MAKEFILE off )
