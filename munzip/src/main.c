#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "../../helperFunctions/fileio.h"

struct __attribute__((packed)) data { uint32_t size; char chr; };
const int BUFFSIZE = 1000;

// size_t decompress_Struct(char* output, struct data);

int main(int argc, char* argv[]){

  FILE *f = openFile(argv[1], "r", NULL);
  if (!f) exit(-1);
  FILE *out = openFile("output", "w", NULL);
  
  struct data compressedDataBuffer[BUFFSIZE];
  char *decompressedData;

 /** decompression and data writing
  *  this can be done in multiple different ways:
  *  1- decompressing each struct and writing it to the output file
  *
  *  2- first, estimating the total size of the data after decompression
  *     then write the whole decompressed data to the file at once
  *
  *  3- Instead, have a buffer, write to it the decompressed data,
  *     write the buffer to the file once it's full or we hit the end of data
  *-----------------------------------------------------------------------------     
  * Below, we implement (3) as it strikes a balance between simplicity and efficiency
  * 
  */

  int blocks;
  do{
    blocks = fread(compressedDataBuffer, sizeof(struct data), BUFFSIZE, f);
    for (int i = 0; i < blocks; i++){
      decompressedData = (char*)malloc(compressedDataBuffer[i].size);
      memset(decompressedData, compressedDataBuffer[i].chr, compressedDataBuffer[i].size);
      fwrite(decompressedData, compressedDataBuffer[i].size, 1, out);
    }
  }while (blocks);
  

  fclose(f);
  fclose(out);
  return 0;
}

