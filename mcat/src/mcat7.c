#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

const int LENGTH = 1024 * 1024; // 4KB is the size of a block of memory
int main(int argc, char* argv[]){
  int fd;
  char buffer[LENGTH];
  int p;

  if (argc < 2){
    fd = STDIN_FILENO;
    do{
      read(fd, buffer, LENGTH);
      puts(buffer);
    }while(buffer);
  }

  for (int i = 1; i < argc; i++){
    fd = open(argv[i], O_RDONLY);
  
    if (fd == -1){
      printf("mcat: cannot open file\n");
      return 1;
    }

    do{
      p = read(fd, buffer, LENGTH);
      write(STDOUT_FILENO, buffer, p); // efficient writing and works well with fread
    }while(p == LENGTH);
    close(fd);
  }
}
