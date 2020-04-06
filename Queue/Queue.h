
#define ROGUEVALUE '\0'

// An item in the queue
typedef struct node {
	char letter;          // The data in this node
	struct node* next;   // The next queue entry towards the tail of the queue
} Node;

// Queue abstract data type
typedef struct {
    Node* head;         // Head (front) of the queue
    Node* tail;         // Tail (back) of the queue
} Queue;

// Queue operations
Queue* initQueue(void);
bool isEmpty(Queue* Q);
void enqueue(Queue* Q, char ch);
char dequeue(Queue* Q);


