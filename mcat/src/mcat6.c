#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _LARGE_FILES

// const int LENGTH = 1024 * 1024; // 4KB is the size of a block of memory
int main(int argc, char* argv[]){
  FILE *f;
  int LENGTH = 1024 * 1024;
  char* buffer = NULL;
  int p;

  if (argc < 2){
    f = stdin;
    buffer = malloc(LENGTH);
    do{
      fgets(buffer, LENGTH, f);
      puts(buffer);
    }while(buffer);
  }

  for (int i = 1; i < argc; i++){
    f = fopen(argv[i], "r");
  
    if (!f){
      printf("mcat: cannot open file\n");
      return 1;
    }
    fseek(f, 0, SEEK_END);
    LENGTH = ftell(f);
    fseek(f, 0, SEEK_SET);
    buffer = malloc(LENGTH);
    printf("Buffer allocated %d bytes!\n", LENGTH);

    p = fread(buffer, 1, LENGTH, f);
    fwrite(buffer, 1, p, stdout); // efficient writing and works well with fread
    fclose(f);
  }
}
