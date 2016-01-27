# systeme_expert_0+
Projet C++ de master 1 en binome.
Le projet était à l'origine un repos svn qui à été transformé en dépôt git.

Ma binome à été rendue anonyme inutile de la chercher.


##Configurer et compiler avec Cmake
###Méthode automatique.
Exécutez simplement le fichier de configuration comme ceci :
* _./configure_

**Cette configuration ne fonctionne que pour les machines GNU/Linux**

###Méthode manuelle.
Pour compiler les fichier tapez dans un terminal :
* _cmake -G"Unix Makefiles"_
* Suivez le Lisezmoi.txt pour configurer le cache.
* _make_

**La commande _cmake -G_ est à adapter à votre système d'exploitation**

##Exécution
Exemple d'exécution :
* _./bin/client lorraine.txt_

Les erreurs ne sont volontairement pas très explicites du fait de la masse
de travail du devoir, il nous à été demandé de ne pas pousser cette
aspect. Il n'est ainsi pas possible pour le moment de savoir quel règle
à déclenché un problème.

##Générer la documentation développeur
Pour générer la documentation placez vous à la racine du dépôt et tapez :
* _doxygen_
