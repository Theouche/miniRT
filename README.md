# miniRT

## Description

`miniRT` est un projet de raytracer minimaliste écrit en C. Le projet implémente un rendu 3D simple avec prise en charge des formes géométriques de base, des lumières, des matériaux, et des scènes personnalisées. Il s'agit d'un projet pédagogique visant à comprendre et à implémenter les concepts fondamentaux d'un moteur de rendu 3D.

## Fonctionnalités

- Chargement de scènes depuis des fichiers de configuration.
- Rendu en temps réel de formes géométriques comme les sphères et les plans.
- Gestion des sources lumineuses pour générer des ombres et des reflets simples.
- Génération d'images à partir des scènes 3D spécifiées.

## Installation

Pour compiler le projet, vous aurez besoin d'un compilateur compatible avec le C (comme `gcc` ou `clang`) et de la bibliothèque `mlx` pour la gestion des fenêtres graphiques.

### Étapes d'installation :

1. Clonez le dépôt dans votre répertoire local :
   ```bash
   git clone <url_du_projet>
   cd miniRT


2. Compilez le projet avec le Makefile :
    make

3. Lancez le programme avec une scène de test :
    ./miniRT scenes/test_scene.rt


## Utilisation

Le projet prend en charge les scènes spécifiées dans des fichiers `.rt`. Ces fichiers décrivent la position des objets, des caméras, et des lumières. Voici un exemple de structure de fichier `.rt` :


# Exemple de scène
A 0.2 255,255,255
C -50,0,20 0,0,1 70
L -40,50,0 0.7 255,255,255
sp 0,0,20 20 255,0,0
pl 0,0,0 0,1,0 0,255,0


- `A` : Définition de l'ambiance de la scène.
- `C` : Position de la caméra.
- `L` : Position de la source de lumière.
- `sp` : Sphère avec ses coordonnées, son rayon et sa couleur.
- `pl` : Plan avec ses coordonnées et sa couleur.

### Commandes pour naviguer dans la scène

Pendant l'exécution, vous pouvez interagir avec la scène en utilisant les commandes suivantes :

- **Déplacement de la caméra :**
  - `W` : Avancer
  - `S` : Reculer
  - `A` : Déplacer à gauche
  - `D` : Déplacer à droite
  - `Q` : Monter
  - `E` : Descendre

- **Rotation de la caméra :**
  - `Flèche Haut` : Tourner vers le haut
  - `Flèche Bas` : Tourner vers le bas
  - `Flèche Gauche` : Tourner vers la gauche
  - `Flèche Droite` : Tourner vers la droite

- **Zoom et dézoom :**
  - `+` : Zoom avant
  - `-` : Zoom arrière

- **Autres commandes :**
  - `ESC` : Quitter la scène et fermer l'application.

Ces commandes vous permettent d'explorer librement la scène 3D et de mieux observer les objets et les effets de lumière.


## Dossiers du projet

- `includes` : Contient les fichiers d'en-tête utilisés dans le projet.
- `srcs` : Contient le code source du projet.
- `scenes` : Dossier avec des fichiers de scènes prêts à être utilisés.
- `resources` : Fichiers de ressources supplémentaires comme des textures ou des exemples de configuration.
- `objs` : Dossier généré pour stocker les fichiers objets lors de la compilation.
- `archives` : Archive des versions précédentes du projet.


