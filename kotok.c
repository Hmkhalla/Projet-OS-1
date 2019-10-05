#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
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
	if (id > table->len){
		table = (player*) realloc(table, id*sizeof(player));
		table->len = id;
	}
	if (table[id-1].id != id){
		table[id-1].id = id;
		table[id-1].score = 0;
		table[id-1].victories = 0;
	}
	table[id-1].score += score;
	if (score) table[id-1].victories += score;
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
	for (int i = 0;i<table->len;i++)  printf("%i %f %i\n", table[i].id, table[i].score, table[i].victories);
	printf("size is %i\n", table->len);
}

int store(FILE* output, player* table){
	for (int i = 0;i<table->len;i++)  fprintf(output, "%i %f %i\n", table[i].id, table[i].score, table[i].victories);
	return ferror(output);
}

int main(int argc, char**argv){
	int x, y; 
	float z;
	FILE* fin;
	FILE* out;
	player* table = NULL;
	/*player* table =  init_memory(); Cette écriture cause des erreurs, pourquoi ? */
	if (argc != 3) return EXIT_FAILURE;
	else{
		const char* IPATH = argv[1];
		const char* OPATH = argv[2];
		printf("%s\n%s\n", IPATH, OPATH);
		if (fin = fopen(IPATH, "r")){
			table = init_memory();
			for (int i=0; fscanf(fin, "%d %d %f", &x,&y,&z) != EOF; i++){
				add_player(table, x, z);
				add_player(table, y, fabsf(z-1));
			};
			imprimer_liste(table);
			fclose(fin);
			if(out = fopen(OPATH, "w")){
				printf("%d\n",store(out, table));
				fclose(out);
			}
		}else  return EXIT_FAILURE;
		free(table);
		printf("rip ?\n");
	}
}
