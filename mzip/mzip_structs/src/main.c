#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "../../../helperFunctions/fileio.h"

struct __attribute__((packed)) data { uint8_t size; char chr; };

struct data* compress_data(char *s){
  struct data *d = malloc(sizeof(struct data) * 100);
  d[0].size = 0;
  d[0].chr = s[0]; 
  size_t c = 0;
  
  for (int i = 0; i < strlen(s); i++){
    if (s[i] == d[c].chr) d[c].size++;
    else{
      c++;
      d[c].size = 1;
      d[c].chr = s[i];
    }
  }
  d[c+1].chr = '\0';
  return d;
}

#define SIZE 1024*1024

int main(int argc, char* argv[]){
  
  if (!argc){
    fputs("mzip: input file not provided\nmzip filename\n",stderr);
    return -1;
  }

  FILE* f = openFile(argv[1], "r", NULL);
  FILE* out = openFile("out", "w", NULL);
  struct data *d = malloc(SIZE * sizeof(struct data));

  d[0].size = 1;
  d[0].chr = fgetc(f);
  
  for (int i = 0; d[i].chr != EOF; i++){
    for (int c = fgetc(f); c != EOF; c = fgetc(f)){
      if (c == d[i].chr) d[i].size++;
      else{
        i++;
        d[i].size = 1;
        d[i].chr = c;
      }
      if (i == SIZE){
        fwrite(d, SIZE * sizeof(struct data), 1, out);
        i = 0;
      }
    }
  }

  for (int i = 0; d[i].chr != '\0'; i++)
    fwrite(d+i, sizeof(struct data), 1, out);
  

  fclose(f);
  fclose(out);
  return 0;
}


