# systeme_expert_0+
Projet C++ de master 1 en binome.
Le projet était à l'origine un repos svn qui à été transformé en depot git.

Ma binome à été rendue anonyme inutile de la chercher.


##Configurer et compiler avec Cmake
###Méthode automatique.
Exécutez simplement le fichier de configuration comme ceci :
_./configure_

###Méthode manuelle.
Pour compiler les fichier tapez dans un terminal :
    cmake -G"Unix Makefiles"
    make

##Exécution
Exemple d'exécution :
    ./bin/client lorraine.txt

##Générer la documentation développeur
Pour générer la documentation placez vous à la racine du dépôt et tapez :
    doxygen
