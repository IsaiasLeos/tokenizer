#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define ORIGINALSIZE 10

int string_length(char *userInput) {
    int length = 0; //length holder
    while (userInput[length] != '\0') {
        length++; //count each letter
    }
    return length;
}

int find_word_start(char* userInput, int index) {
    while (userInput[index] != '\0') {
        if (is_valid_character(userInput[index])) {
            return index; //return index of a valid character
        }
        index++; //traversal
    }
    return 0;
}

int find_word_end(char* userInput, int index) {
    while (userInput[index] != '\0') {
        if (!is_valid_character(userInput[index])) {
            return index; //return index of a invalid character
        }
        if (userInput[index + 1] == '\0') {
            index++;
            return index; //if NULL character is found
        }
        index++;
    }
}

char is_valid_character(char c) {
    return c > 32 && c < 127; //character validation
}

int count_words(char* userInput) {
    printf("Word at: ");
    int start = 0, end = 0, counted = 0, i = 0;
    int length = string_length(userInput); //return length of user input
    while (!(length == i) && !(length - 1 == i)) {
        start = find_word_start(userInput, end); //keep track of where a word starts
        end = find_word_end(userInput, start); //keep track of where a word ends
        printf("[%d, %d] ", start, end);
        i = end;
        if (end == 0 && start == 0) break;
        counted++;
    }
    printf("\n");
    return counted;
}

char** tokenize(char* userInput) {
    printf("###Tokenizing###\n");
    int numWords = count_words(userInput); //amount of words
    int start = 0, end = 0, i = 0, j = 0, wordCount = 0;
    char **tokenArr = (char**) malloc((numWords + 1) * sizeof (char*));
    for (i = 0; i < numWords; i++) {
        start = find_word_start(userInput, end); //keep track of where a word starts
        end = find_word_end(userInput, start); //keep track of where a word ends
        wordCount = end - start;
        tokenArr[i] = (char*) malloc((wordCount + 1) * sizeof (char)); //allocate memory inside the char**
        for (j = 0; j < wordCount; j++) {//loop for the size of the word
            if (userInput[j + start] != ' ') {//while there is no space continue
                tokenArr[i][j] = userInput[j + start]; //tokenize user input
            }
        }
        tokenArr[i][j] = '\0'; //assign null character
    }
    tokenArr[i] = '\0'; //assign null character
    return tokenArr;
}

void print_tokens(char** userInput) {
    printf("###Printing Tokens###\n");
    int i = 0;
    while (userInput[i]) {//while there something continue
        //traverse through tokens
        printf("Token at %d: %s\n", i, userInput[i]);
        i++; //increment
    }
}

void free_tokens(char** userInput) {
    int i = 0;
    while (userInput[i]) {//while there something continue
        //free first set of tokens
        free(userInput[i]);
        i++; //increment
    }
    free(userInput); //free the pointer pointer
}
