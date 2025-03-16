compile:
	mkdir -p build/
	gcc ./src/main.c -o ./build/mzip.out

debug:
	mkdir -p build/
	gcc ./src/main.c -g -o ./build/mzip.out
	gdb ./build/mzip.out

run:
	./build/mzip.out

clean:
	rm *.o
