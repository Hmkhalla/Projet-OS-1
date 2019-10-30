#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "lib.h"

int main(int argc, char**argv){
	if (argc != 3) return EXIT_FAILURE; //vérification des paramètres d'entrée
	int x, y;
	float z;
	FILE* fin = NULL;
	FILE* out = NULL;
	structArray* table = NULL;
	const char* IPATH = argv[1];
	const char* OPATH = argv[2];
	if ((fin = fopen(IPATH, "r")))
	{
		table = init_memory();
		for (int i=0; fscanf(fin, "%d %d %f", &x,&y,&z) != EOF; i++)
		{
			if (table == NULL || add_player(table, x, z) == NULL || add_player(table, y, fabsf(z-1)) == NULL )
			{//fermeture du fichier in avant de quitter le programme à cause d'une erreur d'allocation ou de réallocation de mémoire
				fclose(fin);
				return EXIT_FAILURE;
			}
		};
		fclose(fin);
		if((out = fopen(OPATH, "w")))
		{
			store(out, table);
			fclose(out);
		}
		else
		{// erreur d'ouverture du fichier out
			delete_table(table);
			return EXIT_FAILURE;
		} 
		delete_table(table);
		return EXIT_SUCCESS;
	}
	else  return EXIT_FAILURE;	// erreur d'ouverture du fichier in
}
