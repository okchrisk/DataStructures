#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_WORD_SIZE 256

typedef struct{
	char word[MAX_WORD_SIZE];
} NodeData;

typedef struct treenode {
	NodeData data; // struct inside a struct
	struct treenode* left;
	struct treenode* right;
} TreeNode;

typedef struct {
	TreeNode* root;
} BinaryTree;

TreeNode* newTreeNode(NodeData node) {
	TreeNode* p = (TreeNode*) malloc(sizeof(TreeNode));
	p->data = node; // Copies the node data
	p->left = p->right = NULL;
	return p;
}

TreeNode* findOrInsert(BinaryTree* bt, char str[]) {
	NodeData node;
	strcpy(node.word, str); // Put 'str' in a node data structure
	if (bt->root == NULL) // Is tree empty?
		return bt->root = newTreeNode(node); // Returns value assigned

	TreeNode* curr = bt->root; // Temporary pointer, current position
	int cmp;
	while ((cmp = strcmp(node.word, curr->data.word)) != 0) {
		if (cmp < 0) { // Should we go left?
			if (curr->left == NULL)
				return curr->left = newTreeNode(node);
			curr = curr-> left;
		} 
		else { // Must be right
			if (curr->right == NULL)
				return curr->right = newTreeNode(node);
			curr = curr->right;
		}
	}
printf("Item was found\n"); // If we reach here, item was found in the tree!
return curr;
}

void inOrder(TreeNode* node) {
	if (node != NULL) {
		inOrder(node->left);
	printf("%s ", node->data.word);
	inOrder(node->right);
	}
}

