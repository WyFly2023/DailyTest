//
// Created by wyf on 2023/10/16.
//
#include <stdio.h>

#define MaxSize 10

typedef struct Stack
{
    int data[MaxSize];
    int top;
}Stack;

void InitStack(Stack *s)
{
    s->top = 0;
}

void Push(Stack *s, int e)
{
    if(s->top == MaxSize)
        return;
    s->data[s->top++] = e;
}

void Pop(Stack* s)
{
    if(s->top > 0)
        s->top--;
}

void printStack(Stack* s)
{
    for(int i = 0; i < s->top; ++i)
        printf("%d ",s->data[i]);
    printf("\n");
}

int main()
{
    Stack s;
    InitStack(&s);
    Push(&s, 1);
    Push(&s, 2);
    Push(&s, 3);
    Push(&s, 4);
    printStack(&s);
    Pop(&s);
    Pop(&s);
    return 0;
}