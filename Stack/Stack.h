
#define ROGUEVALUE -2147483648

// An item on the stack
typedef struct node {
	int number;          // The value of this node
	struct node* next;   // Pointer to the next node
} Node;

// Stack abstract data type
typedef struct {
    Node* top;          // Top of stack
} Stack;

// Stack operations
Stack* initStack(void);
bool isEmpty(Stack* S);
void push(Stack* S, int num);
int pop(Stack* S);


