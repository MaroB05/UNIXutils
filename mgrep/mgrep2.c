#include "../helperFunctions/functions.h"
#include <stdio.h>
#include <sys/queue.h>
const int LENGTH = 1024;

int main(int argc, char* argv[]){

  FILE *f;
  char buffer[LENGTH];
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

    // TODO: implement it using a queue
    // we can hava a pline (pointer to line) which we use to move over the lines
    
    int lines = 1;
    int l = 0;
    char* pline = buffer;
    do{
      p = getchars(buffer, LENGTH, f);
      if (p){
        l = count(buffer, '\n');
      }
      
    }while(p);

    // int lines = 1;
    // int line;
    // int index;
    // do{
    //   p = getlines(buffer, LENGTH, f, (size_t *)&lines);
    //   // printf("%s\n", buffer);
    //   if(p != -1){
    //     for (int i = 0; i < strlen(buffer) - strlen(argv[1]);){
    //       index = i + find(argv[1], buffer + i);
    //       // printf("%d, %s\n", index, buffer);
    //       if (index != -1){
    //         line = lines - count(buffer + index, '\n') + 1;
    //         printf("%d: %s", line, slice_delim(buffer, index, "\n"));
    //         // i += strlen(argv[1]) + 1;
    //         i += find("\n", buffer);
    //       }
    //       else i++;
    //     }
    //   }
    //   // line++;
    // }while(p != -1);

    fclose(f);
  }
  
  return 0;
}

