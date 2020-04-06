#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int  number;
	struct node* next;
} Node;

static Node* head = NULL;
static Node* prev = NULL;
// newly added

Node* createNode(int num) {
	Node* nd   = (Node*)malloc(sizeof(Node));
	nd->number = num; //Put the value in the node
	nd->next = NULL; // Next pointer is null for now
	return nd;    // Return a pointer to the new node
}

void printList(void) {
	Node* temp = head;  // Start at head
//  Loop as long as there are more nodes
	while(temp != NULL) {
		printf("%d\n", temp->number);
		temp = temp->next; // Go on to the next node
	}
}

Node* deleteNode(Node* nd, int value) {
	int len = 0;
	Node* temp = nd;  // Start at given node
	while(temp != NULL) {
		temp = temp->next;
		len++;
	}

	if(value > len) {
		printf("Index not in range of size of linked list");
		return 0;
	}

	temp = head; // start from beginning
	prev = NULL;
	for(int i = 1; i < value; i++) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == head) {  // Is this the first node?
		head = temp->next;
	} else {
		prev ->next = temp->next;
	}
	free(temp);  // Deallocated the deleted node


}
