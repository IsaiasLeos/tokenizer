#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

List* init_history() {
	List *history = (List*) malloc(sizeof (Item));
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
	int id = 0;

	if (node == NULL) {//Insert item into the list for the first time
		list->root = (Item*) malloc(sizeof (Item));
		list->root->id = id;
		list->root->str = userInputTemp;
		list->root->next = NULL;
	} else {
		id++;
		//Traverse the list until node->next is null
		while (node->next != NULL) {
			node = node->next;
			id++;
		}

		//Put new item into the non-empty list
		node->next = (Item*) malloc(sizeof (Item));
		node->next->id = id;
		node->next->str = userInputTemp;
		node->next->next = NULL;
	}
}

char* get_history(List* list, int id) {

	Item *node = list->root;

	while (node != NULL) {
		if (node->id == id) {//check for the id
			return node->str; //return the char pointer if matches id
		}
		node = node->next; //traverse the list
	}
}

void print_history(List* list) {

	Item *node = list->root;

	while (node != NULL) {//if node isn't null
		printf("%d - %s\n", node->id, node->str); //print information
		node = node->next; //traverse the list
	}
	printf("------------------------------\n");
}

void free_history(List* list) {

}