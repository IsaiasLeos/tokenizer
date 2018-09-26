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
  printf(">");//validation for input
  int i = 0;
  char c = getchar();//get user input
  while (c != '\n') {//populate array with user input
    sentence[i++] = c;
    c = getchar();
  }
  sentence[i] = '\0';
}

void copy_array(char* source, char* destination, int size) {
  int i;
  for (i = 0; i < size; i++) {//copy from source to destination
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
    //check for a valid character
    if (is_valid_character(str[i])) {
      return i; //return index of valid character
    }
    i++;//incrementation for traversal
  }
  return 0;
}



int find_word_end(char* str, int i) {
  while (str[i] != '\0') {
    //check for a non-valid character
    if (!is_valid_character(str[i])) {
      return i;//return index of a invalid character
    }
    if (str[i + 1] == '\0') {
      return i++;//no spacing found at the end of the word
    }
    i++;
  }
}


char is_valid_character(char c) {
  return c > 32 && c < 127;//check for validation of character
}



int count_words(char* str) {
  int start = 0, end = 0, counted = 0, i = 0;
  while(str[i + 1] != '\0'){
    start = find_word_start(str,end);//save starting index
    end = find_word_end(str,start);//save ending index
    i = end;//save ending as current index
    counted++;//count valid words
  }
  return counted;
}
