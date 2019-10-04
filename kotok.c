#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define INIT_CAPACITY 5

typedef struct
{
	int id;
	float score;
	int victories;
	int len;
} player;


/* inserer_noeud: insère un noeud avec la valeur passée en paramètre */
player* add_player(player* table, int id, float score)
{
	if (id <= table->len){
		table[id-1].id = id;
		table[id-1].score += score;
		if (score) table[id-1].victories += score;
	}else{
		table = (player*) realloc(table, id*sizeof(player));
		table->len = id;
		table[id-1].id = id;
		table[id-1].score += score;
		if (score) table[id-1].victories += score;
	}
	return table;
}

player* init_memory()
{
	player* table = malloc(sizeof(player)*INIT_CAPACITY);
	table->len = INIT_CAPACITY;
	return table;
}


/* supprimer_tete: supprimer le noeud de tête */
/*player* supprimer_tete(player* tete)
{
	if ( tete == NULL )
		return NULL;
	else
	{
		//player* nouvelle_tete = tete->suivant;
		free(tete);
		return nouvelle_tete;
	}
}*/

/* imprimer_liste: imprime la liste à l'écran */
void imprimer_liste(player* table){
	int i = 0;
	while(i<table->len){
		printf("%i %f %i\n", table[i].id, table[i].score, table[i].victories);
		i++;
	}
	printf("size is %i\n", table->len);
}

int main(){
	player* table = init_memory();
	add_player(table, 3, 1);
	add_player(table, 3, 0);
	add_player(table, 3, 0.5);
	add_player(table, 3, 1);
	add_player(table, 5, 1);
	table = add_player(table, 10, 1);
	imprimer_liste(table);
	free(table);
	return 0;
}
