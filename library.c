#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct noeud_t
{
	int id;
	float score;
	int victories;
	struct noeud_t* suivant;
} player;



/* creer_noeud: renvoie un pointeur vers un nouveau noeud avec la valeur passée en paramètre */
player* alloc_player(int id, float score, int victories)
{
	player* nouveau_noeud = malloc(sizeof(player));
	nouveau_noeud->id = id;
	nouveau_noeud->score = score;
	nouveau_noeud->victories = victories;
	nouveau_noeud->suivant = NULL;
	return nouveau_noeud;
}


/* inserer_noeud: insère un noeud avec la valeur passée en paramètre */
player* add_player(player* tete, int id, float score, int victories)
{
	player* nouvelle_tete = alloc_player(id, score, victories);
	nouvelle_tete->suivant = tete;
	return nouvelle_tete;
}

player* init_memory()
{
	player* last = alloc_player(-1,-1,-1);
	for (int i=0; i<4; i++){
		last = add_player(last,i,-1,-1);
	}
	return last;
}


/* supprimer_tete: supprimer le noeud de tête */
player* supprimer_tete(player* tete)
{
	if ( tete == NULL )
		return NULL;
	else
	{
		player* nouvelle_tete = tete->suivant;
		free(tete);
		return nouvelle_tete;
	}
}

/* imprimer_liste: imprime la liste à l'écran */
void imprimer_liste(player* tete){
	while(tete != NULL){
		printf("%i %f %i\n", tete->id, tete->score, tete->victories);
		tete = tete->suivant;
	}
}

int main(){
	player* last = init_memory();
	imprimer_liste(last);
	return 0;
}
