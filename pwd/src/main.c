#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
  size_t size = 10;
  char* buff = (char *) malloc(size);

  while(!getcwd(buff, size)){
    if (errno == ERANGE){
      size *= 2;
      buff = (char *) realloc(buff, size);
    }
  }
  puts(buff);
  return 0;
}
