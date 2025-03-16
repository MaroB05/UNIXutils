compile: 
	gcc src/mcat1.c -o ./build/mcat1.out
	gcc src/mcat2.c -o ./build/mcat2.out 
	gcc src/mcat3.c -o ./build/mcat3.out 
	gcc src/mcat4.c -o ./build/mcat4.out
	gcc src/mcat5.c -o ./build/mcat5.out
	gcc src/mcat6.c -o ./build/mcat6.out
	gcc src/mcat7.c -o ./build/mcat7.out

clean: 
	rm *.o

test:
	./build/mcat5.out ../Shakespeare_data.csv

all:
	gcc mcat.c ../helperFunctions/functions.c -c
	gcc mcat.o functions.o -o mcat.out
	rm *.o
