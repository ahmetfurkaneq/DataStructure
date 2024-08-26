#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    struct Node *next;
};
struct Stack
{
    struct Node *top;
};

struct Stack *stackOlustur()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}
void push(struct Stack *stack, int data)
{
    struct Node *willbeadded = (struct Node *)malloc(sizeof(struct Node));
    willbeadded->data
}
