#include <stdio.h>
const int LENGTH = 8 * 1024; // 4KB the size of a block of memory
int main(int argc, char* argv[]){

  FILE *f;
  char buffer[LENGTH];
  char* p;
  for (int i = 1; i < argc; i++){
    f = fopen(argv[i], "r");
  
    if (!f){
      printf("mcat: cannot open file\n");
      return 1;
    }

    do{
      p = fgets(buffer, LENGTH, f);
      if(p) fputs(buffer, stdout);
    }while(p);

    fclose(f);
  }
}
