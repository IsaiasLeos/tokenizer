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
        char *userInput = (char*) malloc(size * sizeof (char));
        char *userInputTemp = (char*) malloc(size * sizeof (char));
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

    printf(">");
    int i, size;
    char c;

    size = ORIGINALSIZE;
    c = getchar();

    while (c != '\n') {
        userInput[i] = c;
        c = getchar();
        i++;
        if (i >= size) {
            size *= 2;
            copy_array(userInput, userInputTemp, size);
            userInput = (char*) malloc(size * sizeof (char));
            copy_array(userInputTemp, userInput, size);
            userInputTemp = (char*) malloc(size * sizeof (char));
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
