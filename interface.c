#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
/* Obtains user input and populates the given char array. */
void get_user_input(char*);

int main() {
    int x; //output holder
    char size = 10;

    while (1) {
        char *sentence = (char*) malloc(size * sizeof (char));
        free(sentence);
        get_user_input(sentence); //assign user input
        x = string_length(sentence); //return length of user input
        printf("Length: %d", x);
        printf("\n");
        x = count_words(sentence); //count words in user input
        printf("Count: %d", x); //word count
        printf("\n");
    }
    return 0;
}

void get_user_input(char* sentence) {
    printf(">"); //input validation
    int i = 0;
    char c = getchar(); //get user input
    while (c != '\n') {//populate array with user input
        sentence[i++] = c;
        c = getchar();
    }
    sentence[i] = '\0';
}