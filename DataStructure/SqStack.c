#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef int ElemType;
#define MaxSize 10
typedef struct Stack{
    ElemType data[MaxSize];
    int top;
}Stack;

void initStack(Stack *stack){
    stack->top = 0;
}

bool EmptyStack(Stack *stack){
    assert(stack);
    return stack->top == 0;
}
void Push(Stack *stack, ElemType e){
    assert(stack);
    assert(!(stack->top ==  MaxSize));
    stack->data[stack->top++] = e;
}

ElemType Pop(Stack *stack){
    assert(!EmptyStack(stack));
    ElemType e = stack->data[stack->top - 1];
    stack->top--;
    return e;
}

void printStack(Stack *stack){
    assert(stack);
    for(int i = stack->top - 1; i >= 0; i--)
        printf("%d ",stack->data[i]);
    printf("\n");
}

int main(){
    Stack stack;
    initStack(&stack);
    Push(&stack,1);
    Push(&stack,2);
    Push(&stack,3);
    Push(&stack,4);
    //Pop(&stack);
    printStack(&stack);
    return 0;
}