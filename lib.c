#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define INIT_CAPACITY 5

typedef struct
{
	int id;
	float score;
	int victories;
} player;

typedef struct
{
	int len;
	player* table;
} structArray;

void delete_table(structArray* table)
{
	free(table);
}

/* inserer_noeud: insère un noeud avec la valeur passée en paramètre */
Table* add_player(structArray* Table, int id, float score)
{
	if (id > Table->len){
		if ((Table->table = (player*) realloc(Table->table, id*sizeof(player))) == NULL)
		{
			delete_table(Table);
			exit(1);
		}
		Table->len = id;
	}
	if (Table->table[id-1].id != id){
		Table->table[id-1].id = id;
		Table->table[id-1].score = 0;
		Table->table[id-1].victories = 0;
	}
	Table->table[id-1].score += score;
	if (score) Table->table[id-1].victories += score;
	return Table;
}

Table* init_memory()
{
	Table* Table = NULL;
	if (((Table = malloc(sizeof(Table))) == NULL) && ((Table->table = malloc(sizeof(player)*INIT_CAPACITY)) == NULL))
		{
			delete_table(Table);
			exit(1);
		}
	Table->len = INIT_CAPACITY;
	return Table;
}

void imprimer_liste(Table* Table){
	for (int i = 0;i< Table->len;i++)  printf("%i %f %i\n", Table->table[i].id, Table->table[i].score, Table->table[i].victories);
	printf("size is %i\n", Table->len);
}

int store(FILE* output, Table* Table){
	for (int i = 0;i< Table->len;i++)  fprintf(output, "%i %f %i\n", Table->table[i].id, Table->table[i].score, Table->table[i].victories);
	return ferror(output);
}