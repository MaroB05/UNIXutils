#include "../helperFunctions/mstring.h"
#include "../helperFunctions/fileio.h"
#include <stdio.h>
#include <string.h>
const int LENGTH = 1024; //1024;

int main(int argc, char* argv[]){

  FILE *f;
  char* q;
  char buffer[LENGTH];
  char c;
  // size_t n = 60;
  size_t p;

  if(argc == 2){
    do{
      p = getchars(buffer, LENGTH, f);
      if (find(argv[1], buffer)) 
        printf("%s", buffer);
    }while(p != -1);
  }
  else if (argc < 2){
    printf("not enough arguments: mgrep searchterm [file ....]\n");
    return 1;
  }
  if (strcmp(argv[1] ,"") == 0){ return 0;}

  for (int i = 2; i < argc; i++){
    f = fopen(argv[i], "r");

    if (!f){
      printf("mgrep: cannot open file\n");
      return 1;
    }

    
    int lines = 0;
    char* s = buffer;
    do{
      p = getchars(buffer, LENGTH, f);
      q = strtok(strdup(buffer), "\n");
      while (q){
        s += strlen(q);
        if (strcmp(q, buffer))
          lines++;
        if (find(argv[1], q) != -1){
          printf("%d: %s\n", lines, q);
        }else{
          printf("%d moving bytes!\n", lines);
          memmove(buffer, s, strlen(q));
        }
        q = strtok(NULL, "\n");
      }
      
    }while(p);

    fclose(f);
  }
  
  return 0;
}

