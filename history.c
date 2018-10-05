#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

List* init_history() {
    List *history = (List*) malloc(sizeof (Item));
    history->root = 0;
    return history;
}

void add_history(List* list, char* str) {
    char *strCopy = (char*) malloc(string_length(str) * sizeof (char));
    int i = 0;
    //copy string into a new string
    while (str[i]) {
        strCopy[i] = str[i];
        i++;
    }
    strCopy[i] = '\0';
    Item *node = list->root;
    int index = 0;
    //Insert item into the list for the first time
    if (node == 0) {
        list->root = (Item*) malloc(sizeof (Item));
        list->root->id = index;
        list->root->str = strCopy;
        list->root->next = 0;
    } else {
        index++;
        //Traverse the list until iter->next is null
        while (node->next != 0) {
            node = node->next;
            index++;
        }
        //Put new item into the list
        node->next = (Item*) malloc(sizeof (Item));
        node->next->id = index;
        node->next->str = strCopy;
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

/* Free all Items and the List. */
void free_history(List* list) {
    Item *head = list->root;
    Item *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
//What should free history do?
//History commands?
//Interface of History
