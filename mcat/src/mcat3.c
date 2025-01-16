#include <stdio.h>

const int LENGTH = 8 * 1024; // 4KB the size of a block of memory
int main(int argc, char* argv[]){
  FILE *f;
  char buffer[LENGTH+1];
  int p;
  for (int i = 1; i < argc; i++){
    f = fopen(argv[i], "r");
  
    if (!f){
      printf("mcat: cannot open file\n");
      return 1;
    }

    do{
      p = fread(buffer, 1, LENGTH, f);
      buffer[p] = '\0';
      fputs(buffer, stdout);
    }while(p == LENGTH);
    fclose(f);
  }
}
