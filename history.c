#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

List* init_history() {
    List *history = (List*) malloc(sizeof (Item));
    history->root = NULL;
    return history;
}

void add_history(List* list, char* userInput) {
    
    char *userInputTemp = (char*) malloc(string_length(userInput) * sizeof (char));
    
    int i = 0;
    while (userInput[i]) {//copy string into a new string
        userInputTemp[i] = userInput[i];
        i++;
    }
    userInputTemp[i] = '\0';
    
    Item *node = list->root;
    int index = 0;
    
    if (node == NULL) {//Insert item into the list for the first time
        list->root = (Item*) malloc(sizeof (Item));
        list->root->id = index;
        list->root->str = userInputTemp;
        list->root->next = 0;
    } else {
        index++;
        //Traverse the list until iter->next is null
        while (node->next != NULL) {
            node = node->next;
            index++;
        }
        
        //Put new item into the list
        node->next = (Item*) malloc(sizeof (Item));
        node->next->id = index;
        node->next->str = userInputTemp;
        node->next->next = 0;
    }
}

char* get_history(List* list, int id) {
    
    Item *node = list->root;
    
    while (node != NULL) {
        if (node->id == id) {
            return node->str;
        }
        node = node->next;
    }
}

void print_history(List* list) {
    
    Item *node = list->root;
    
    while (node != NULL) {
        printf("%d - %s\n", node->id, node->str);
        node = node->next; //assign the next one
    }
    printf("------------------------------\n");
}

void free_history(List* list) {

}