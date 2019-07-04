#include "Stack.h"
#include <stdio.h>

typedef struct _Item
{
    int a;
    double b;
    char c;
} Item;

int main(int argc, char **argv)
{
    // Initialize data
    Stack stack;
    stackInit(&stack, sizeof(Item));
    const int ints[5] = {1001, 1002, 1003, 1004, 1005};
    const double doubles[5] = {1001.111111, 1002.222222, 1003.333333, 1004.444444, 1005.555555};
    const char chars[5] = {'a', 'b', 'c', 'd', 'e'};

    printf("\n");

    // Push items onto the stack
    for (int i = 0; i < 5; ++i)
    {
        Item item = {ints[i], doubles[i], chars[i]};
        printf("Pushing {item.a: %d, item.b: %f, item.c: %c} onto stack.\n", item.a, item.b, item.c);
        stackPush(&stack, &item);
    }

    printf("\nStack size is %lu.\n\n", stackSize(&stack));

    // Pop items off the stack
    for (int i = 0; i < 5; ++i)
    {
        Item item;
        stackPop(&stack, &item);
        printf("Popping {item.a: %d, item.b: %f, item.c: %c} off the stack.\n", item.a, item.b, item.c);
    }

    printf("\nStack is empty? ");
    if (stackEmpty(&stack))
        printf("Yes.\n\n");
    else
        printf("No.\n\n");

    return 0;
}

