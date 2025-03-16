#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
  const int f = open(argv[1], O_RDONLY);
  const int file_size = lseek(f, 0, SEEK_END);
  lseek(f, 0, SEEK_SET);

  if (f == -1){
    puts("file not opened!");
    perror("error opening file");
    return -1;
  }
  
  char* file = (char*)mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, f, 0);
  fwrite(file, 1, file_size, stdout);
  return 0;
}
