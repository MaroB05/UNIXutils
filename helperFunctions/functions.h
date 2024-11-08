#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

//Files
FILE *openFile(char* filename, char* mode, char* err_msg);



// ---------------------String Manipulation-----------------
// TODO: create a routine for printing a whole line (use strncpy?)

char *slice(const char* s, const uint start, const uint end);
char *slice_delim(const char* s, const uint start, const char *delim);
int find(const char* target, const char* text);
size_t count(const char* s, const char delim);

// reads characters from a File f and writes it buffer with size n
// returns the number of lines read in this time
size_t getchars(char* const buffer, const size_t n, FILE *f); 
size_t getlines(char * const buffer, const size_t n, FILE *f, size_t *const lines);

/* --------------------Custom Strings------------------------*/
struct myString{
  char *s;
  int len;
};
