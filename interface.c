#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define ORIGINALSIZE 10

char* get_user_input(char*, char*);
void copy_array(char*, char*, int);

int main() {
    char size = ORIGINALSIZE;
    while (1) {
        char *userInput = (char*) malloc(size * sizeof (char));//save user input
        char *userInputTemp = (char*) malloc(size * sizeof (char));//temp input
        userInput = get_user_input(userInput, userInputTemp);
        int x = string_length(userInput); //return length of user input
        printf("Length: %d", x);
        printf("\n");
        int y = count_words(userInput); //count words in user input
        printf("Count: %d", y); //word count
        printf("\n");
        free(userInput);
        free(userInputTemp);
    }
    return 0;
}

char* get_user_input(char *userInput, char *userInputTemp) {

    printf(">");//output validation
    int i, size;
    char c;

    size = ORIGINALSIZE;//create initial size
    c = getchar();

    while (c != '\n') {
        userInput[i] = c;//populate
        c = getchar();//obtain next char
        i++;//increment
        if (i >= size) {
            size *= 2;
            copy_array(userInput, userInputTemp, size);//copy user to temp
            userInput = (char*) malloc(size * sizeof (char));//double user
            copy_array(userInputTemp, userInput, size);//copy temp to user
            userInputTemp = (char*) malloc(size * sizeof (char));//double temp
        }
    }
    userInput[i] = '\0';
    return userInput;
}

void copy_array(char* src, char* dest, int size) {
    int i;
    for (i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}