# Documentation du projet Epitech Corewar

## Description du fichier home_arena.c

Le fichier home_arena.c contient l'implémentation des fonctions principales pour l'exécution du jeu Corewar. Il définit la logique du jeu et l'arène virtuelle où les joueurs s'affrontent.

### Fonctions

#### `int check_win(st_c *st_core)`

Cette fonction vérifie si l'un des joueurs a gagné la partie. Elle met à jour le cycle de mort (`cycle_to_die`) en fonction du nombre de joueurs en vie et de la constante `NBR_LIVE`. Si le cycle de mort atteint 0, la fonction renvoie 1 pour indiquer la fin de la partie. Sinon, elle vérifie si le nombre de cycles écoulés (`tempo_cycle`) est supérieur au cycle de mort actuel. Si c'est le cas, elle appelle la fonction `check_live` pour vérifier le nombre de joueurs en vie. Si le nombre de joueurs en vie est inférieur ou égal à 1, la fonction renvoie 1 pour indiquer la fin de la partie. Sinon, elle renvoie 0 pour indiquer que la partie continue.

##### Paramètres
- `st_core`: Un pointeur vers une structure `st_c` contenant les informations du jeu.

##### Retour
- `int`: 1 si la partie est terminée, 0 sinon.

#### `int sub_cut_indice(int *tmp_int, int n, int i, int min_idx)`

Cette fonction auxiliaire est utilisée par la fonction `cut_indice` pour trouver l'indice du plus petit élément dans un tableau d'entiers `tmp_int`. Elle recherche l'indice du plus petit élément à partir de l'indice `i + 1` jusqu'à `n`. L'indice du plus petit élément est renvoyé.

##### Paramètres
- `tmp_int`: Un pointeur vers un tableau d'entiers.
- `n`: Le nombre d'éléments dans le tableau.
- `i`: L'indice de départ pour la recherche.
- `min_idx`: L'indice du plus petit élément trouvé jusqu'à présent.

##### Retour
- `int`: L'indice du plus petit élément trouvé.

#### `void cut_indice(int arr[], int n, int *cut_indice)`

Cette fonction trie les indices d'un tableau `arr` en fonction des valeurs correspondantes dans un tableau `tmp_int`. Elle utilise la fonction `sub_cut_indice` pour trouver les indices des éléments les plus petits et les trie en conséquence. Les indices triés sont stockés dans le tableau `cut_indice`.

##### Paramètres
- `arr`: Un tableau d'entiers.
- `n`: Le nombre d'éléments dans le tableau.
- `cut_indice`: Un pointeur vers un tableau d'entiers pour stocker les indices triés.

#### `void prepa_pos_champion(st_c *st_core)`

Cette fonction prépare les positions des champions dans l'arène virtuelle. Elle alloue et initialise un tableau `pos_champ` pour stocker les positions des champions. Elle utilise la fonction `cut_indice` pour trier les indices des champions en fonction de leur numéro de programme (`prog_nb`).

##### Paramètres
- `st_core`: Un pointeur vers une structure `st_c` contenant les informations du jeu.

#### `int home_arena(st_c *st_core)`

Cette fonction est la fonction principale qui exécute le jeu Core

war. Elle initialise les variables nécessaires pour le jeu, prépare les champions, détermine les positions des champions et exécute les cycles du jeu jusqu'à ce qu'un joueur gagne ou que la partie se termine. Elle appelle également les fonctions `play_player` pour exécuter les actions des joueurs et `display_arena` pour afficher l'arène dans le cas où `dump` est atteint.

##### Paramètres
- `st_core`: Un pointeur vers une structure `st_c` contenant les informations du jeu.

##### Retour
- `int`: 0 si la partie est terminée avec succès, 84 en cas d'erreur.

## Inclusion des fichiers

Le fichier home_arena.c inclut les fichiers suivants :
- my.h : Fichier d'en-tête contenant des déclarations de fonctions et des définitions de types utilisées dans le projet.
- struct_all.h : Fichier d'en-tête contenant la définition de la structure `st_c` qui regroupe les informations du jeu.
- op.h : Fichier d'en-tête contenant des constantes et des définitions de structures utilisées dans le jeu Corewar.

## Conclusion

La documentation ci-dessus présente les fonctions implémentées dans le fichier home_arena.c du projet Epitech Corewar. Ces fonctions sont essentielles pour le bon déroulement du jeu et la gestion de l'arène virtuelle.