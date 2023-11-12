#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct SNode{
    int data;
    struct SNode* next;
}SNode;

typedef struct Stack{
    SNode* top;
}Stack;

void initStack(Stack *s){
    s->top = NULL;
}

SNode* ApplyNode(int e){
    SNode* newnode = (SNode*)malloc(sizeof(SNode));
    if (newnode != NULL){
        newnode->data = e;
        newnode->next = NULL;
    }
    return newnode;
}

bool StackEmpty(Stack *stack){
    return stack->top == NULL;
}

void Push(Stack* s, int e){
    SNode* newnode = ApplyNode(e);
    newnode->next = s->top;
    s->top = newnode;
}

int Pop(Stack* s){
    assert(!(s->top == NULL));
    int x = s->top->data;
    SNode* tmp = s->top;
    s->top = tmp->next;
    free(tmp);
    return x;
}

void printStack(Stack* s){
    SNode* cur = s->top;
    while (cur != NULL){
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

//进制的转换
void decimalConversion(Stack *s, int n, int base){
    int tmp = n;
    while(tmp){
        Push(s,tmp % base);
        tmp /= base;
    }
    while(s->top != NULL){
        printf("%d ",Pop(s));
    }
}

//求n的阶乘
unsigned long long Factorial(Stack *s, int n){
    if(n > 1) {
        while (n > 1) {
            printf("%d! ",n);
            Push(s, n--);
        }
    }
    printf("\n");
    unsigned long long ret = 1;
    while (!StackEmpty(s)) {
        ret *= Pop(s);
        printf("%lld ",ret);
    }
    return ret;
}

int main(){
    Stack s;
    Push(&s,1);
    Push(&s,2);
    Push(&s,3);
    Push(&s,4);
    Push(&s,5);
    printStack(&s);
    Pop(&s);
    printStack(&s);
    return 0;
}