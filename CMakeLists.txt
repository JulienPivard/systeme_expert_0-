# Version de cmake demandée.
CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )

# Chemin des répertoires contenant les fichiers entêtes.
INCLUDE_DIRECTORIES(
    src/include/modele
    src/include/builders
    src/include/builders/lorraine
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
    src/modele/OperateurAbstrait.cpp
    src/modele/OperateurPlus.cpp
    src/modele/OperateurMoins.cpp
    src/modele/OperateurMul.cpp
    src/modele/OperateurDiv.cpp

    src/modele/VisiteurFormeAbstrait.cpp
    src/modele/VisiteurForme.cpp

    src/modele/FormeAbstraite.cpp
    src/modele/FormeAbstraiteConclusion.cpp
    src/modele/FormeConclusionBoolTrue.cpp
    src/modele/FormeConclusionBoolFalse.cpp
    src/modele/FormeConclusionEntierExpression.cpp
    src/modele/FormeConclusionEntierFait
    src/modele/FormeConclusionSymboliqueConstante.cpp
    src/modele/FormeConclusionSymboliqueFait.cpp

    src/modele/FormeAbstraitePremisse.cpp
    src/modele/FormePremisseBoolTrue.cpp
    src/modele/FormePremisseBoolFalse.cpp
    src/modele/FormePremisseEntierExpression.cpp
    src/modele/FormePremisseEntierFait.cpp
    src/modele/FormePremisseSymboliqueConstante.cpp
    src/modele/FormePremisseSymboliqueFait.cpp

    src/modele/RegleAbstraite.cpp
    src/modele/RegleSansPremisse.cpp
    src/modele/RegleAvecPremisse.cpp

    src/builders/lorraine/jeton.cpp
    src/builders/lorraine/fabriqueJeton.cpp
    src/builders/lorraine/lexical.cpp
    src/builders/lorraine/syntaxique.cpp
    src/builders/lorraine/monException.cpp

    src/builders/lorraine/concreteBuilderLorraine.cpp
    src/builders/directeur.cpp

    src/modele/MoteurInference.cpp
    )
# Faire parler le make.
set( CMAKE_VERBOSE_MAKEFILE off )
