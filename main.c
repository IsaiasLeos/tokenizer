#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

void get_user_input(char*);
/* Would read user input and remove any extra spaces. */
void fix_user_sentence(char*);



int main() {
  int x; //output holder
  int cont = 1;
  char *sentence; //to carry all user input



  while (1 && cont) {
    get_user_input(sentence);
    printf("finding length...");
    printf("\n");
    x = string_length(&sentence[0]); //obtain length of string
    printf("length - %d", x);
    printf("\n");
    printf("not implemented");
    printf("\n");
    printf("not implemented");
    printf("\n");
    x = find_word_start(&sentence[0], 0); //obtain index to next word
    printf("next word start at - %d", x);
    printf("\n");
    x = find_word_end(&sentence[0], 0); //obtain index to next word
    printf("next word end at - %d", x);
    printf("\n");
    printf("not implemented");
    printf("\n");
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
  fix_user_sentence(sentence);
  printf("%s", sentence); //print sentence
  printf("\n");

}

void fix_user_sentence(char* str) {
  int i, j;
  for (i = j = 0; str[i]; ++i) {
    if (str[i] != ' ' || (str[i - 1]) != ' ') {
      str[j++] = str[i];
    }
  }
  str[j] = '\0';
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
  int index = 0; //index of next word
  char c = 1; //boolean
  while (str[i] != '\0') {
    if (str[i] == ' ' && c) {//TODO improve
      index = i + 1; //set index of next word
      c = 0;
    }
    i++;
  }
  return index;
}



int find_word_end(char* str, int i) {
  int index = 0; //index of next word
  char c = 1, d = 1; //boolean
  while (str[i] != '\0' || str[i] == ' ') {
    i++;
  }
  while (str[i] != '\0' || str[i] == ' ') {
    i++;
  }
  return index;
}



char is_valid_character(char c) {
  return c > 31 && c < 127;
}



int count_words(char* str) {
  int i = 0;
  int words = 0;
  char c;
  while (str[i] != '\0') {
    c = (str[i] == ' ');
    if (c) {
      words++;//count for whitespace
    }
    i++;
  }
  return words + 1;
}
