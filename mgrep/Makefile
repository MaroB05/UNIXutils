

compilea: 
	gcc mgrep.c -o mgrep.out 

compileb:
	gcc mgrep2.c -o mgrep2.out 

runb:
	./mgrep2.out

clean: 
	rm *.o

all:
	gcc mgrep.c ../helperFunctions/functions.c -c
	gcc mgrep.o functions.o -o mgrep.out
	rm *.o
