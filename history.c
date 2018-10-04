#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history() {
    List *history = (List*) malloc(sizeof (Item));
    history->root = 0;
    return history;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
 */
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

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char* get_history(List* list, int id) {
    Item *iter = list->root;
    while (iter != NULL) {
        if (iter->id == id) {
            return iter->str;
        }
    }
}

/* Print the entire contents of the list. */
void print_history(List* list) {
    Item *iter = list->root;
    while (iter != NULL) {
        printf("%d - %s\n", iter->id, iter->str);
        iter = iter->next; //assign the next one
    }
}

/* Free all Items and the List. */
void free_history(List* list) {

}
//What should free history do?
//History commands?
//Interface of History