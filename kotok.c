#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "lib.h"

int main(int argc, char**argv){
	int x, y;
	float z;
	FILE* fin = NULL;
	FILE* out = NULL;
	Table* table = NULL;
	if (argc != 3) return EXIT_FAILURE;
	else{
		const char* IPATH = argv[1];
		const char* OPATH = argv[2];
		printf("%s\n%s\n", IPATH, OPATH);
		if ((fin = fopen(IPATH, "r"))){
			table = init_memory();
			for (int i=0; fscanf(fin, "%d %d %f", &x,&y,&z) != EOF; i++){
				add_player(table, x, z);
				add_player(table, y, fabsf(z-1));
			};
			imprimer_liste(table);
			fclose(fin);
			if((out = fopen(OPATH, "w"))){
				printf("%d\n",store(out, table));
				fclose(out);
			}
		}else  return EXIT_FAILURE;
		delete_table(table);
		printf("rip ?\n");
	}
}
