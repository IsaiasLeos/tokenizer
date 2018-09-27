#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
/* Obtains user input and populates the given char array. */
void get_user_input(char*);
/* Copies the array given to the next. */
void copy_array(char*, char*, int size);

int main() {
  int x; //output holder
  char size = 10;
  char *sentence = (char*) malloc(size * sizeof (char));
  free(sentence);
  while (1) {
    get_user_input(sentence);//assign user input
    x = string_length(sentence);//return length of user input
    printf("Length: %d", x);
    printf("\n");
    x = count_words(sentence);//count words in user input
    printf("Count: %d", x);//word count
    printf("\n");
  }
  return 0;
}

void get_user_input(char* sentence) {
  printf(">");//input validation
  int i = 0;
  char c = getchar();//get user input
  while (c != '\n') {//populate array with user input
    sentence[i++] = c;
    c = getchar();
  }
  sentence[i] = '\0';
}


/*Copy from source to destination*/
void copy_array(char* source, char* destination, int size) {
  int i;
  for (i = 0; i < size; i++) {
    destination[i] = source[i];
  }
  printf("%s", destination);//print for confirmation
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
    //return index of a valid character
    if (is_valid_character(str[i])) {
      return i; //set index of next word
    }
    i++;//traversal
  }
  return 0;
}

int find_word_end(char* str, int i) {
  while (str[i] != '\0') {
    //return index of a invalid character
    if (!is_valid_character(str[i])) {
      return i;
    }
    if (str[i + 1] == '\0') {
      return i++;//if NULL character is found
    }
    i++;
  }
}


char is_valid_character(char c) {
  return c > 32 && c < 127;//character validation
}

int count_words(char* str) {
  int start = 0, end = 0, counted = 0, i = 0;
  while (str[i + 1] != '\0') {
    start = find_word_start(str, end);//keep track of where a word starts
    end = find_word_end(str, start);//keep track of where a word ends
    printf("Word at: %d, %d",start,end);
    printf("\n");
    i = end;//save ending as current index
    counted++;//count valid words
  }
  return counted;
}
