# Systeme Expert 0+

Projet C++ universitaire de master 1 informatique en binome. Le projet
était à l'origine un repos svn qui à été transformé en dépôt git.

Ma binôme a été rendue anonyme inutile de la chercher.

Le devoir consistait à mettre en place un système expert 0+ en étant un
peu guidé sur les _design patterns_ à utiliser, mais l'architecture de
l'application et l'agencement des _design patterns_ entre eux est de notre
conception. Parmi les consignes qui nous avaient été données :
* Respecter la philosophie du langage.
* Les allocations dynamiques seront effectuées via des pointeurs
  intelligents de la bibliothèque standard _shared-ptr_.
* Les messages d'erreurs seront volontairement négligés étant donné la
  masse déjà conséquente de travail.
* La grammaire à implémenter est la grammaire _lorraine_.

L'état du dépot lors du rendu du devoir en version final est accessible
via le tag **renduDevoir**. Les commit suivant sont des modifications
suggéré par le professeur lors du rendu des notes avec la correction
détaillée.

## Configurer et compiler avec Cmake
### Méthode automatique.
Exécutez simplement le fichier de configuration comme ceci :
* `./configure`

**Cette configuration ne fonctionne que pour les machines GNU/Linux**

### Méthode manuelle.
Pour compiler les fichier tapez dans un terminal :
* `cmake -G"Unix Makefiles"`
* Suivez le Lisezmoi.txt pour configurer le cache.
* `make`

**La commande `cmake -G <Generateur>` est à adapter à votre système
d'exploitation**

## Exécution
Exemple d'exécution :
* `./bin/Release/client lorraine.txt`

Les erreurs ne sont volontairement pas très explicites du fait de la masse
de travail du devoir, il nous a été demandé de ne pas pousser cet aspect.
Il n'est ainsi pas possible pour le moment de savoir quelle règle
à déclenché un problème.

## Générer la documentation développeur
Pour générer la documentation placez-vous à la racine du dépôt et tapez :
* `doxygen`
