

compile: 
	gcc mcat.c -c
	gcc mcat.o -o mcat.out

clean: 
	rm *.o

all:
	gcc mcat.c ../helperFunctions/functions.c -c
	gcc mcat.o functions.o -o mcat.out
	rm *.o
