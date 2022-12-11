#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <climits>
#include <cstring>



// a node stored in a stack.
class StackNode {
public:
    int val;
    StackNode* next;

    StackNode(int dataArg)
    {
    	val = dataArg;
    	next = NULL;
    }

    StackNode(int dataArg, StackNode * nextArg)
    {
        	val = dataArg;
        	next = nextArg;
    }

};

// checks if stack is empty
int isStackEmpty(StackNode* root);


void pushToStack(StackNode** root, int data);


int popFromStack(StackNode** root);


#endif
