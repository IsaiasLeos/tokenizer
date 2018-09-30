#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
/* Obtains user input and populates the given char array. */
void get_user_input(char*);
int main() {
  int x; //output holder
  while (1) {
    char sentence[20];
    get_user_input(sentence); //assign user input
    x = string_length(sentence); //return length of user input
    printf("Length: %d", x);
    printf("\n");
    x = count_words(sentence); //count words in user input
    printf("Count: %d", x); //word count
    printf("\n");
    //free(sentence);
  }
  return 0;
}

void get_user_input(char* sentence) {
  printf(">"); //input validation
  char c = getchar(); //get user input
  while (c != '\n') {//populate array with user input
    *sentence++ = c;
    c = getchar();
  }
  *sentence = '\0';
}
