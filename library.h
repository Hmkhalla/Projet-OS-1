#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noeud_t
{
	int id;
	float score;
	int victories;
	int len;
	struct noeud_t* suivant;
} player;

/* creer_noeud: renvoie un pointeur vers un nouveau noeud avec la valeur passée en paramètre */
player* init_memory();

/* inserer_noeud: insère un noeud avec la valeur passée en paramètre */
player* add_player(int id, float score, int victories, player* tete);

int find_player(int id);

/* supprimer_tete: supprime le noeud de tête */
player* remove_memory(player* tete);

/* imprimer_liste: imprime la liste à l'écran */
void store(player* tete);
