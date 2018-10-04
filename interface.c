#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define ORIGINALSIZE 10
/* Get the user input and dynamicly allocate memory according to that input. */
char* get_user_input(char*, char*);
/* Copy arry from source to destination. */
void copy_array(char*, char*, int);

int main() {
    char size = ORIGINALSIZE;
    int id = 0;
    List *history = init_history();
    while (1) {
        id++;
        char **tokenArr;
        char *userInput = (char*) malloc(size * sizeof (char)); //save user input
        char *userInputTemp = (char*) malloc(size * sizeof (char)); //temp input
        userInput = get_user_input(userInput, userInputTemp);
	if(userInput[0] == '!'){
	  switch(userInput[1]){
	  case 'p':
	    print_history(history);
	    break;
	  case 'g':
	    userInput = get_history(history, userInput[3]);
	    printf("%s",userInput);
	    break;
	  default:
	    printf("Unrecongnized Command...");
	    break;
	  }
	}else{
        int x = string_length(userInput); //return length of user input
        printf("\nLength: %d\n", x);
        int y = count_words(userInput); //count words in user input
        printf("Count: %d\n\n", y); //word count
        tokenArr = tokenize(userInput); //tokenize the input
        print_tokens(tokenArr); //print tokens
        add_history(history, userInput); //add to history
	}
        free_tokens(tokenArr); //free tokens
        free(userInput); //free user input
        free(userInputTemp); //free temp input
    }
    return 0;
}

char* get_user_input(char *userInput, char *userInputTemp) {

    printf(">"); //output validation
    int i, size;
    char c;

    size = ORIGINALSIZE; //create initial size
    c = getchar();

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
    if(userInput[0] == '!') return userInput;
    userInput[i] = '\0'; //assign null character
    return userInput;
}

void copy_array(char* src, char* dest, int size) {
    int i;
    for (i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}
