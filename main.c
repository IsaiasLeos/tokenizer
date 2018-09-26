#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

/*Obtains user input and populates the given char array. */
void get_user_input(char*);
/* Would read user input and remove any extra spaces. */
int main() {
  int x; //output holder
  int cont = 1;
  char *sentence; //to carry all user input

  while (1) {
    get_user_input(sentence);
    x = string_length(&sentence[0]); //obtain length of string
    printf("length - %d", x);
    x = count_words(&sentence[0]);
    printf("count - %d",x);
  }
  return 0;
}


void get_user_input(char* sentence) {
  printf(">");
  int i = 0; //index holder
  char c = getchar();
  while (c != '\n') {
    sentence[i++] = c;
    c = getchar();
  }
  sentence[i] = '\0'; //make sure string is ended
  //printf("%s", sentence); //print sentence
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

int find_word_start(char* str, int i) {
  while (str[i] != '\0') {
    if (is_valid_character(str[i])) {//TODO improve
      return i; //set index of next word
    }
    i++;
  }
  return 0;
}

int find_word_end(char* str, int i) {
  while(str[i] != '\0'){
    if(!is_valid_character(str[i])) {
      return i;
    }
    i++;
  }
}


char is_valid_character(char c) {
  return c > 32 && c < 127;
}



int count_words(char* str) {
  int start = 0, end = 0, counted = 0, i = 0;
  while(str[i] != '\0'){
    start = find_word_start(str,end);
    end = find_word_end(str,start);
    i = end;
    counted++;
  }
  return counted;
}
