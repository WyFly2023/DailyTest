/*
	Stack
	顺序栈的基本操作
*/


typedef int ElemType;
#define MaxSize 10
typedef struct Stack{
    ElemType data[MaxSize];
    int top;
}Stack;

//初始化
void initStack(Stack *stack){
    stack->top = 0;
}

//判空
bool EmptyStack(Stack *stack){
    assert(stack);
    return stack->top == 0;
}

//入栈
void Push(Stack *stack, ElemType e){
    assert(stack);
    assert(!(stack->top ==  MaxSize));
    stack->data[stack->top++] = e;
}

//出栈
ElemType Pop(Stack *stack){
    assert(!EmptyStack(stack));
    ElemType e = stack->data[stack->top - 1];
    stack->top--;
    return e;
}
	