//MKHALLATI Hassan 000459680
#ifndef LIB_H
#define LIB_H

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

structArray* add_player(structArray* table, int id, float score);
/*
	Rajoute le struct joueur au tableau et retourne le pointeur de la structure.
	Retourne le pointeur NULL en cas d'erreur et libère la mémoire précedement allouée.
*/

structArray* init_memory();
/*
    Initialise de la structure tableau, alloue un espace memoire de 5 joueurs et retourne le pointeur de la structure.
	Retourne le pointeur NULL en cas d'erreur et libère la mémoire précedement allouée.
*/

void imprimer_liste(structArray* table);
/*
	Renvoie le tableau sur la console
*/

int store(FILE* output, structArray* table);
/*
	Stock le tableau sur le fichier et ignore les trous du tableau
*/

void delete_table(structArray* table);
/*
    Libère la mémoire accordée au tableau.
*/


#endif