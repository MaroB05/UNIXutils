#include <stdio.h>

const int LENGTH = 8 * 1024; // 4KB is the size of a block of memory
int main(int argc, char* argv[]){
  FILE *f;
  char buffer[LENGTH];
  int p;
  for (int i = 1; i < argc; i++){
    f = fopen(argv[i], "r");
  
    if (!f){
      printf("mcat: cannot open file\n");
      return 1;
    }

    do{
      p = fread(buffer, 1, LENGTH, f);
      fwrite(buffer, 1, p, stdout); // efficient writing and works well with fread
    }while(p == LENGTH);
    fclose(f);
  }
}
