#include <stdio.h>
#include "../../../helperFunctions/fileio.h"
#include "../../../helperFunctions/mstring.h"

int main(int argc, char* argv[]){

  FILE* f;
  char* buffer = 0;
  char* old_buffer = 0;
  size_t n = 4096;
  ssize_t p;
  //TODO: replace find with strstr()
  if (strcmp(argv[1] ,"") == 0){ return 0;}

  if(argc == 2){
    do{
      p = getline(&buffer, &n, stdin);
      if (buffer != old_buffer && old_buffer)
        free(old_buffer);
      if (find(argv[1], buffer)) 
        printf("%s", buffer);
    }while(p != -1);
  }
  else if (argc < 2){
    printf("not enough arguments: mgrep searchterm [file ....]\n");
    return 1;
  }

  //TODO: search on all of the files that exist
  for (int i = 2; i < argc; i++){
    f = fopen(argv[i], "r");
    
    if (!f){
      printf("mgrep: cannot open file\n");
      return 1;
    }

    int line = 1;
    int index = 0;
    do{
      p = getline(&buffer, &n, f);
      if (buffer != old_buffer && old_buffer)
        free(old_buffer);
      if(p != -1){
        index = find(argv[1], buffer);
        if (index != -1){
          printf("%d: %s", line, buffer);
        }
      }
      line++;
    }while(p != -1);

    fclose(f);
  }

  if (buffer)
    free(buffer);
  return 0;
}

