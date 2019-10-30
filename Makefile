#MKHALLATI Hassan 000459680
kotok : lib.o
	gcc lib.o kotok.c -o kotok -std=c11 -Wall -Werror -Wpedantic
	rm -rf *.o
lib.o : lib.c
	gcc -c lib.c -o lib.o
clean : 
	rm -rf *.o
	