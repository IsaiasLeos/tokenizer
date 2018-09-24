#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

/*Obtains user input and populates the given char array. */
void get_user_input(char*);

int main(){

  int x;//output holder
  int cont = 1;//boolean

  char *sentence;
  while(1){
    get_user_input(sentence);
    x = string_length(&sentence[0]);
    printf("length -> %d",x);
    printf("\n");

    printf("not implemented - is_valid_character()");

    printf("not implemented - find_word_start()");

    printf("not implemented - find_word_end()");

    printf("not implemented - cound_words()");
  }
}

void get_user_input(char* sentence){
  printf(">");
  int i = 0;//index holder
  char c = getchar();

  while(c != '\n'){//populate char array
    sentence[i++] = c;
    c = getchar();
  }
  sentence[i] = '\0';//make sure array ends
  printf("%s",sentence);//print sentence
  printf("\n");
}

int string_length(char *str) {
  int count = 0; //length holder
  while (*str != '\0') {
    count++; //count each letter
    *str++; //traverse char array
  }
  return count;
}

char is_valid_character(char c){
  return c > 31 && c < 127;
}

int find_word_start(char* str, int i){
  int index = 0;//index of the next word
  char c = 1;
  while(str[i] != '\0'){
    if(str[i] == ' ' && c){
      index = i + 1;//save position of next word
      c = 0;//found word, prevent re-run
    }
    i++;
  }
  return index;
}
