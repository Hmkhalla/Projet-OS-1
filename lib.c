//MKHALLATI Hassan 000459680
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lib.h"
#define INIT_CAPACITY 5

void delete_table(structArray* Array)
{
	/*
    libère la mémoire du tableau de joueur et ensuite la structure tableau
	*/
	free(Array->table);
	free(Array);
}

structArray* init_memory()
{
	/*
    initialise de la structure, alloue un espace memoire de 5 joueurs et initialise la capacité du tableau
	Retourne  la structure en cas de succès, NULL en cas d'échec
	*/
	structArray* Table = NULL;
	if ((Table = (structArray*)malloc(sizeof(structArray))) == NULL)
		{ //erreur d'allocation de mémoire primaire (struct)
			return NULL;
		}
	else if ((Table->table = (player*) malloc(sizeof(player)*INIT_CAPACITY)) == NULL)
		{// erreur d'allocation secondaire (tableau)
			delete_table(Table);
			return NULL;
		}
	Table->len = INIT_CAPACITY;
	return Table;
}

structArray* add_player(structArray* Table, int id, float score)
{
	/*
	Rajoute le struct joueur au tableau. Réallocation de la mémoire si nécessaire. Les clés du tableau sont les id des joueurs (afin d'obtenir une recherche rapide des joueurs)
	Retourne  la structure en cas de succès, NULL en cas d'échec
	*/
	if (id > Table->len)
	{
		if ((Table->table = (player*) realloc(Table->table, id*sizeof(player))) == NULL)
		{ //erreur de réallocation de mémoire
			delete_table(Table);
			return NULL;
		}
		Table->len = id;
	}
	if (Table->table[id-1].id != id)
	{// initialisation des données lors de l'ajout du joueur
		Table->table[id-1].id = id;
		Table->table[id-1].score = 0;
		Table->table[id-1].victories = 0;
	}
	Table->table[id-1].score += score;
	if (score) Table->table[id-1].victories += score;
	return Table;
}


void imprimer_liste(structArray* Table){
	/*
	renvoie le tableau sur la console
	*/
	for (int i = 0;i< Table->len;i++)  printf("%i %.1f %i\n", Table->table[i].id, Table->table[i].score, Table->table[i].victories);
}

int store(FILE* output, structArray* Table){
	/*
	stock le tableau sur le fichier et ignore les trous du tableau (dans le cas ou l'ensemble des id n'est pas un ensemble compact)
	*/
	for (int i = 0;i< Table->len;i++)  if (Table->table[i].id !=0) fprintf(output, "%i %.1f %i\n", Table->table[i].id, Table->table[i].score, Table->table[i].victories);
	return ferror(output);
}