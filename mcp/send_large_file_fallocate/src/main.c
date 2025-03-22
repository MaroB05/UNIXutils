#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sendfile.h>
#define _LARGE_FILES

int main(int argc, char* argv[]){

  if (argc < 3){
    fputs("usage: mcp file1 file2", stderr);
    return -1;
  }
  
  int src = open(argv[1], O_RDONLY);
  if (src == -1){
    printf("error opening %s", argv[1]);
    perror("");
    return -1;
  }
  
  int dist = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
  if (dist == -1){
    printf("error opening %s", argv[2]);
    perror("");
    return -1;
  }

  off_t file_size = lseek(src, 0, SEEK_END);
  printf("the file is %ld\n", file_size);
  lseek(src, 0, SEEK_SET);

  posix_fallocate(dist, 0, file_size); // allocate all of the needed space ahead of righting.

  while (sendfile(dist, src, NULL, file_size));

  return 0;
}
