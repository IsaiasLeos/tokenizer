#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main(){

  int i = 0;//index holder
  int x;//output holder
  int cont = 1;//boolean

  char *sentence;
  printf(">");
}

int string_length(char *str) {
  int count = 0; //length holder
  while (*str != '\0') {
    count++; //count each letter
    *str++; //traverse char array
  }
  return count;
}

int is_valid_character(char c){
  return c > 31 && c < 127;
}
