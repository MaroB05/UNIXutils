#include <stdio.h>
#include <stdbool.h>
#include "../../../helperFunctions/fileio.h"
#include "../../../helperFunctions/mstring.h"


void search(const char* term, char filename[], FILE* stream);

int main(int argc, char* argv[]){

  FILE* f;
  if(argc == 1){ 
    fputs("not enough arguments: mgrep [term] [file1 file2 ...]\n", stderr);
    return 1;
  }

  if(argc == 2) {
    search(argv[1], NULL, stdin);
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
    
    search(argv[1], argv[2], f);
    fclose(f);
  }

  // if (buffer)
  //   free(buffer);
  return 0;
}

//inlined function for efficiency

inline void search(const char* term, char filename[], FILE* stream){
  int line = 1;
  int index = 0;
  char* buffer = 0;
  char* old_buffer = 0;
  size_t n = 4096;
  bool found = false;

  while(getline(&buffer, &n, stream) != -1) {
    if (buffer != old_buffer && old_buffer)
      free(old_buffer);
    if (strstr(buffer ,term)){
      printf("%s:%d: %s", filename, line, buffer);
    }
    line++;
  }
  if (buffer)
    free(buffer);
}

