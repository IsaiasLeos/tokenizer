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
    int start = 0, end = 0, counted = 0, i = 0;
    int length = string_length(userInput); //return length of user input
    while (!(length == i)) {
        start = find_word_start(userInput, end); //keep track of where a word starts
        end = find_word_end(userInput, start); //keep track of where a word ends
        printf("Word at: %d - %d\n", start, end);
        i = end;
        counted++;
    }
    return counted;
}

char** tokenize(char* userInput) {
    printf("Tokenizing...\n");
    int numWords = count_words(userInput) + 1; //amount of words
    int start = 0, end = 0, i = 0, j = 0;
    char **tokenArr = (char**) malloc((numWords + 1) * sizeof (char**));
    for (i = 0; i < numWords - 1; i++) {
        start = find_word_start(userInput, end); //keep track of where a word starts
        end = find_word_end(userInput, start); //keep track of where a word ends
        tokenArr[i] = (char*) malloc(((end - start) + 1) * sizeof (char)); //double user
        for (j = 0; j < (end - start) + 1; j++) {
            if (userInput[j + start] != ' ') {
                tokenArr[i][j] = userInput[j + start];
            }
        }
        tokenArr[i][j] = '\0';
    }
    tokenArr[i] = '\0';
    return tokenArr;
}

void print_tokens(char** userInput) {
    int i;
    for (i = 0; *userInput[i] != '\0'; ++i) {
        printf("Token at %d: %s\n", i, userInput[i]);
    }
}