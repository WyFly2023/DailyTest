#include <stdio.h>
#include <stdlib.h>

typedef struct SNode
{
    int data;
    struct SNode* next;
}SNode;

typedef struct Stack
{
    SNode* top;
}Stack;

void initStack(Stack *s)
{
    s->top = NULL;
}

SNode* ApplyNode(int e)
{
    SNode* newnode = (SNode*)malloc(sizeof(SNode));
    if (newnode != NULL)
    {
        newnode->data = e;
        newnode->next = NULL;
    }
    return newnode;
}

void Push(Stack* s, int e)
{
    SNode* newnode = ApplyNode(e);
    newnode->next = s->top;
    s->top = newnode;
}
void Pop(Stack* s)
{
    if (s->top == NULL)
        return;
    SNode* tmp = s->top;
    s->top = tmp->next;
    free(tmp);
}

void printStack(Stack* s)
{
    SNode* cur = s->top;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main()
{
    Stack s;
    initStack(&s);
    Push(&s, 1);
    Push(&s, 2);
    Push(&s, 3);
    Push(&s, 4);
    Pop(&s);
    printStack(&s);

    return 0;
}