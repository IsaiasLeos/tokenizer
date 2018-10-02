#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define ORIGINALSIZE 10

int string_length(char *str) {
    int count = 0; //length holder
    while (str[count] != '\0') {
        count++; //count each letter
    }
    return count;
}

int find_word_start(char* str, int i) {
    while (str[i] != '\0') {
        if (is_valid_character(str[i])) {
            return i; //return index of a valid character
        }
        i++; //traversal
    }
    return 0;
}

int find_word_end(char* str, int i) {
    while (str[i] != '\0') {
        if (!is_valid_character(str[i])) {
            return i; //return index of a invalid character
        }
        if (str[i + 1] == '\0') {
            return i++; //if NULL character is found
        }
        i++;
    }
}

char is_valid_character(char c) {
    return c > 32 && c < 127; //character validation
}

int count_words(char* str) {
    int start = 0, end = 0, counted = 0, i = 0;
    while (str[i + 1] != '\0') {
        start = find_word_start(str, end); //keep track of where a word starts
        end = find_word_end(str, start); //keep track of where a word ends
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