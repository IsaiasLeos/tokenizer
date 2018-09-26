#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

/*Obtains user input and populates the given char array. */
void get_user_input(char*);
/* Would read user input and remove any extra spaces. */
int main() {
  int x; //output holder
  char size = 10;
  char *sentence = (char*) malloc(size * sizeof (char));
  free(sentence);
  while (1) {
    get_user_input(sentence);
    x = string_length(sentence);
    printf("Length: %d", x);
    printf("\n");
    x = count_words(sentence);
    printf("Words: %d", x);
    printf("\n");
  }
  return 0;
}

void get_user_input(char* sentence) {
  printf(">");
  int i = 0;
  char c = getchar();
  while (c != '\n') {
    sentence[i++] = c;
    c = getchar();
  }
  sentence[i] = '\0';
}

void copy_array(char* source, char* destination, int size) {
  int i;
  for (i = 0; i < size; i++) {
    destination[i] = source[i];
  }
  printf("%s", destination);
}

int string_length(char *str) {
  int count = 0; //length holder
  while (*str != '\0') {
    count++; //count each letter
    str++; //traverse char array
  }
  return count;
}

int find_word_start(char* str, int i) {
  while (str[i] != '\0') {
    if (is_valid_character(str[i])) {
      return i; //set index of next word
    }
    i++;
  }
  return 0;
}



int find_word_end(char* str, int i) {
  while (str[i] != '\0') {
    if (!is_valid_character(str[i])) {
      return i;
    }
    if (str[i + 1] == '\0') {
      return i++;
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
