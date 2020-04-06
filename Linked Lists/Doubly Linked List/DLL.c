#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int number;
	struct node* next;
	struct node* prev;
} Node;

static Node* head = NULL;
static Node* tail = NULL;

Node* createNode(int num) {
	Node* nd   = (Node*)malloc(sizeof(Node));
	nd->number = num; // Put the value in the node
	nd->next = NULL;  // Next pointer is null for now
	nd->prev = NULL;  // Prev pointer is null for now
	return nd;    // Return a pointer to the new node
}

void appendNode(int num) {
	Node* nd = createNode(num);  // Allocate new node 'nd'
	if (head ==  NULL) {   // If list is empty
		head =  nd;   // New node is the head (and tail)
	} else {
		tail->next = nd; // Make old tail node point at new one
		nd ->prev = tail; // Make new node point back at old tail
	}
	tail = nd;   // New node becomes the new tail
}

void insertNode(Node* loc, int num) {
	Node* nd = createNode(num);  // Allocate new node 'nd'
	if (loc->next != NULL) {
		loc  ->next->prev = nd; // Node after loc points back to nd
	}
	nd ->next = loc->next; // New node points to node after loc
	loc ->next = nd;  // loc now points to the new node
	nd ->prev = loc;  // New node points back to loc
	if (loc == tail) { // If at end, new node becomes new    tail
		tail = nd;
	}
}

void printList(Node* nd, bool forward) {// Loop as long as there are more nodes
	Node* temp = nd;
	while (temp != NULL) {
		printf("%d\n", temp->number);
		if (forward)
			temp = temp->next; // Go to the next node
		else
			temp = temp->prev; // Go to the previous node
	}
}

void deleteNode(Node* nd) {
	if (nd == head) {   // Deleting head node?
		head = nd->next;
	}
	if (nd == tail) {   // Deleting tail node?
		tail = nd->prev;
	}
	if (nd->next != NULL) {   // Is there a next node?
		nd->next->prev = nd->prev;
	}
	if (nd->prev != NULL) {   // Is there a previous node?
		nd->prev->next = nd->next;
	}
	free(nd);  // Deallocate the deleted node
}

