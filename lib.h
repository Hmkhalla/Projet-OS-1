#ifndef LIB_H
#define LIB_H

typedef struct
{
	int id;
	float score;
	int victories;
	int len;
} player;

typedef struct
{
	int len;
	player* table;
} structArray;

structArray* add_player(structArray* table, int id, float score);

structArray* init_memory();

void imprimer_liste(structArray* table);

int store(FILE* output, structArray* table);

void delete_table(structArray* table);


#endif