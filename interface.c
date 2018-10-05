#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define ORIGINALSIZE 10
/* Get the user input and dynamically allocate memory according to that input. */
char* get_user_input(char*, char*);
/* Copy arry from source to destination. */
void copy_array(char*, char*, int);

void inputInformation(char*, char**);

int main() {
  char size = ORIGINALSIZE;
  List *history = init_history();
  while (1) {
    char **tokenArr;
    char *userInput = (char*) malloc(size * sizeof (char)); //save user input
    char *userInputTemp = (char*) malloc(size * sizeof (char)); //temp input
    userInput = get_user_input(userInput, userInputTemp);
    if (userInput[0] == '!') {
      switch (userInput[1]) {
      case 'p':
	print_history(history);
	break;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
	//todo fix crash if number higher than 9
	userInput = get_history(history, userInput[1] - 48); //remove 48 cause of ascii
	inputInformation(userInput, tokenArr);
	break;
      case 'f':
	printf("Unimplemented Command...\n");
	break;
      default:
	printf("Unrecongnized Command...\n");
	break;
      }
    } else {
      inputInformation(userInput, tokenArr);
      add_history(history, userInput); //add to history
      free(userInput); //free user input
      free(userInputTemp); //free temp input
    }
  }
  return 0;
}

char* get_user_input(char *userInput, char *userInputTemp) {
  
  printf(">"); //output validation
  
  int i, size;
  char c;
  
  size = ORIGINALSIZE; //create initial size
  c = getchar();
  printf("------------------------------\n");
  while (c != '\n') {
    
    userInput[i] = c; //populate
    c = getchar(); //obtain next char
    i++; //increment
    
    if (i >= size) {
      size *= 2; //double size
      copy_array(userInput, userInputTemp, size / 2); //copy original to temp
      userInput = (char*) malloc(size * sizeof (char)); //double original
      copy_array(userInputTemp, userInput, size / 2); //copy temp to original
      userInputTemp = (char*) malloc(size * sizeof (char)); //double temp
    }
  }
  
  if (userInput[0] == '!') return userInput;
  
  userInput[i] = '\0'; //assign null character
  return userInput;
}

void copy_array(char* src, char* dest, int size) {
  int i;
  for (i = 0; i < size; i++) {
    dest[i] = src[i];
  }
}

void inputInformation(char *userInput, char **tokenArr) {
  printf("Word: %s", userInput);
  int x = string_length(userInput); //return length of user input
  printf("\nLength: %d\n", x);
  int y = count_words(userInput); //count words in user input
  printf("Count: %d\n", y); //word count
  tokenArr = tokenize(userInput); //tokenize the input
  print_tokens(tokenArr); //print tokens
  printf("------------------------------\n");
  free_tokens(tokenArr); //free tokens
}
