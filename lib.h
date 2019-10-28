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
} Table;

Table* add_player(Table* table, int id, float score);

Table* init_memory();

void imprimer_liste(Table* table);

int store(FILE* output, Table* table);

void delete_table(Table* table);


#endif