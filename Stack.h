// *
// * Generic implementation of a stack.
// *

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <string.h>

typedef struct Stack_
{
    size_t memSize;
    size_t size;
    struct StackNode *top;
} Stack;

void stackClear(Stack *);
int stackEmpty(const Stack *);
int stackInit(Stack *, const size_t);
int stackPeek(const Stack *, void *);
int stackPop(Stack *, void *);
int stackPush(Stack *, const void *);
size_t stackSize(const Stack *);

#endif