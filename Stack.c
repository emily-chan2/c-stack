#include "Stack.h"

typedef struct StackNode
{
    void *data;
    struct StackNode *next;
} Node;

//------------------------------------------------------------------------------
// Frees all the nodes and data. Top point to NULL, size is reset to zero, but
// memSize is kept intact.
//------------------------------------------------------------------------------
void stackClear(Stack *s)
{
    while(s->size > 0)
    {
        Node *temp = s->top;
        s->top = s->top->next;
        free(temp->data);
        free(temp);
        s->size--;
    }

    s->top = NULL;
}

//------------------------------------------------------------------------------
// Returns 1 if the stack is empty, 0 otherwise.
//------------------------------------------------------------------------------
int stackEmpty(const Stack *s)
{
    return (s->size == 0);
}

//------------------------------------------------------------------------------
// Initializes the stack.
// Returns 0 on success, -1 on failure.
//------------------------------------------------------------------------------
int stackInit(Stack *s, const size_t memSize)
{
    if (memSize > 0)
    {
        s->memSize = memSize;
        s->size = 0;
        s->top = NULL;
        return 0;
    }

    return -1;
}

//------------------------------------------------------------------------------
// Returns by reference the data at the top of the stack.
// Returns 0 on success, -1 on failure.
//------------------------------------------------------------------------------
int stackPeek(const Stack *s, void *data)
{
    if (s->size > 0)
    {
        memcpy(data, s->top->data, s->memSize);
        return 0;
    }

    return -1;
}

//------------------------------------------------------------------------------
// Returns by reference the data at the top of the stack, and removes the top
// node from the stack.
// Returns 0 on success, -1 on failure.
//------------------------------------------------------------------------------
int stackPop(Stack *s, void *data)
{
    if (s->size > 0)
    {
        memcpy(data, s->top->data, s->memSize);

        Node *temp = s->top->next;
        free(s->top->data);
        free(s->top);

        if (s->size > 1)
            s->top = temp;
        else
            s->top = NULL;

        s->size--;
        return 0;
    }

    return -1;
}

//------------------------------------------------------------------------------
// Adds the given data to the top of the stack.
// Returns 0 on success, -1 on failure.
//------------------------------------------------------------------------------
int stackPush(Stack *s, const void *data)
{
    if (s->memSize > 0)
    {
        Node *node = (Node *) malloc(sizeof(Node));
        if (node == NULL)
            return -1;

        node->data = malloc(s->memSize);
        if (node->data == NULL)
        {
            free(node);
            return -1;
        }

        memcpy(node->data, data, s->memSize);

        if (s->size == 0)
            node->next = NULL;
        else
            node->next = s->top;

        s->top = node;
        s->size++;
        return 0;
    }

    return -1;
}

//------------------------------------------------------------------------------
// Returns the size of the stack.
//------------------------------------------------------------------------------
size_t stackSize(const Stack *s)
{
    return s->size;
}