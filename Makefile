kotok_exe : lib.o
	gcc lib.o kotok.c -o kotok_exe
lib.o : lib.c
	gcc -c lib.c -o lib.o