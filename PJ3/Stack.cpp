#include "Stack.h"


// push value to stack
void pushToStack(StackNode** rootNode, int val) {
	StackNode* stackNode = new StackNode(val, *rootNode);
	*rootNode = stackNode;
}

// pop top element of stack and return it.
// returns INT_MIN if stack is empty
int popFromStack(StackNode** root) {
	if (!isStackEmpty(*root)) {
		StackNode* toRemove = *root;
		int result = (*root)->val;
		*root = (*root)->next;
		free(toRemove);
		return result;
	} else {
		return INT_MIN;
	}
}

// check if stack is empty
int isStackEmpty(StackNode* rootNode) {
	return !rootNode;
}

