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
    const int ints[5] = {10, 20, 30, 40, 50};
    const double doubles[5] = {10.1, 10.2, 10.3, 10.4, 10.5};
    const char chars[5] = {'a', 'b', 'c', 'd', 'e'};

    printf("\n");

    // Push items
    for (int i = 0; i < 5; ++i)
    {
        Item item = {ints[i], doubles[i], chars[i]};
        printf("Pushing {item.a: %d, item.b: %.1f, item.c: %c}\n", item.a, item.b, item.c);
        stackPush(&stack, &item);
    }

    printf("\nStack size is %lu\n\n", stackSize(&stack));

    // Pop items
    for (int i = 0; i < 5; ++i)
    {
        Item item;
        stackPop(&stack, &item);
        printf("Popping {item.a: %d, item.b: %.1f, item.c: %c}\n", item.a, item.b, item.c);
    }

    printf("\nStack is empty? ");
    if (stackEmpty(&stack))
        printf("Yes\n\n");
    else
        printf("No\n\n");

    return 0;
}