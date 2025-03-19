#include <fcntl.h>
#include <stdio.h>

int main(int argc, char* argv[]){
  
  if (argc != 3){
    printf("usage: %s source_path destination_path", argv[0]);
    return -1;
  }
  
  int status = rename(argv[1], argv[2]);
  
  if (status == -1){
    perror("mmv");
    return -1;
  }
  
  return 0;
}
