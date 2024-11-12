#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

struct data { uint32_t size; char chr; };

struct data* compress_data(char *s){
  struct data *d = malloc(sizeof(struct data) * 100);
  d[0].size = 0;
  d[0].chr = s[0]; //d[0] = {0, s[0]};
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

int main(){
  char s[] = "aaaabbc";
  struct data *d = (struct data*)compress_data(s);
  
  for (int i = 0; d[i].chr != '\0'; i++){
    printf("%d %c\n", d[i].size, d[i].chr);
  }

  return 0;
}
