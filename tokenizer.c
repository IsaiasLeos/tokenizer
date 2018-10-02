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
            return index++; //if NULL character is found
        }
        index++;
    }
}

char is_valid_character(char c) {
    return c > 32 && c < 127; //character validation
}

int count_words(char* userInput) {
    int start = 0, end = 0, counted = 0, i = 0;
    while (userInput[i + 1] != '\0') {
        start = find_word_start(userInput, end); //keep track of where a word starts
        end = find_word_end(userInput, start); //keep track of where a word ends
        printf("Word at: %d - %d", start, end);
        printf("\n");
        i = end; //save ending as current index
        counted++; //count valid words
        if (start == 0 && end == 0) {
            counted--; //prevent input of just spaces
            break;
        }
    }
    return counted;
}