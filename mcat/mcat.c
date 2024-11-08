#include <stdio.h>
#include "../functions.h"
const int LENGTH = 60;
int main(int argc, char* argv[]){

  FILE *f;
  char buffer[LENGTH];
  size_t p;
  for (int i = 1; i < argc; i++){
    f = fopen(argv[i], "r");
  
    if (!f){
      printf("mcat: cannot open file\n");
      return 1;
    }

    do{
      p = getchars(buffer, LENGTH, f);
      if(p) printf("%s", buffer);
    }while(p);

    fclose(f);
  }
}
