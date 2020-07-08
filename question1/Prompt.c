/*
 ============================================================================
 Name        : Prompt.c
 Author      : 
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	int number;
	struct Node* next;
};

void put(struct Node** hRef, int data){
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); ;
	
	struct Node *last = *hRef;

	newNode->number = data;
    newNode->next = NULL;
    
	if (*hRef == NULL)  
    {  
        *hRef = newNode; 
        return;
    }
    
    while (last->next != NULL){  
        last = last->next;
    }
    last->next = newNode;  
}

void printList(struct Node *node) 
{ 
  while (node != NULL) 
  { 
     printf("%d ", node->number); 
     node = node->next; 
  } 
  printf("\n");
} 

int getElement(struct Node* head, int index){
	struct Node* current = head; 
      
    int aux = 0; 
    while (current != NULL) 
    { 
        if (aux == index) {
            return(current->number); 
        }
        aux++; 
        current = current->next; 
    }
} 

int getFirst(struct Node* head){
	return head->number;
}

int getLast(struct Node* head){
	struct Node* current = head; 
    if (current == NULL){
        return -1;
    }
    while(current->next != NULL){
		current = current->next;
	}
    return current->number;
}

void removeElement(struct Node **hRef, int index) 
{ 
   if (*hRef == NULL) 
      return; 
  
   struct Node* previous = *hRef; 
  
    if (index == 0) 
    { 
        *hRef = previous->next;   
        free(previous);               
        return; 
    } 
  
    for (int i = 0; previous != NULL && i < index-1; i++){ 
         previous = previous->next; 
    }
  
    if (previous == NULL || previous->next == NULL) {
         return; 
    }
  
    struct Node *next = previous->next->next; 
  
    free(previous->next);
  
    previous->next = next;  
} 

void print_entry(char *entry) {
	printf("You entered: %s\n", entry);
}

int main(int argc, char *argv[]) {
	char input[201];
    struct Node* head = NULL; 
    

	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}

		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		}

		if(strncmp(input,"put", 3) == 0){
			put(&head, input[4] - '0');
			printList(head);
		}

		if(strncmp(input,"get", 3) == 0){
			int index = input[4] - '0' - 1;
			printf("%d\n",getElement(head, index));
		}

		if(strncmp(input,"first", 5) == 0){
			printf("%d\n",getFirst(head));
		}

		if(strncmp(input,"last", 4) == 0){
			printf("%d\n",getLast(head));
		}

		if(strncmp(input,"list", 4) == 0){
			printList(head);
		}

		if(strncmp(input,"clear", 5) == 0){
			head = NULL;
			printList(head);
		}

		if(strncmp(input,"remove", 6) == 0){
			int index = input[7] - '0' - 1;
			removeElement(&head, index);
			printList(head);
		}
		

		print_entry(input);
	}

	return EXIT_SUCCESS;
}