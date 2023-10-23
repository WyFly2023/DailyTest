/*
	链式栈的基本操作
*/

typedef int Elemtype;
typedef struct SNode{
	Elemtype data;
	struct LNode* next;
}SNode;

typedef struct Stack{
	SNode * top;
}Stack;

void InitStack(Stack* s){
	s->top = NULL;
}

//申请节点
SNode* Apply(Elemtype e){
	SNode * newnode = (SNode*)malloc(sizeof(SNode));
	if(newnode != NULL){
		newnode->data = e;
		newnode->next = NULL;
	}
	return newnode;
}

//入栈
void Push(Stack* s, Elemtype e){
	SNode * newnode = Apply(e);
	newnode->next = s->top;
	s->top = newnode;
}

//判断栈是否为空
bool StackEmpty(Stack *s){
	return s->top == NULL;
}

//出栈
Elemtype Pop(Stack * s){
	assert(!StackEmpty(s));
	Elemtype x = s->top->data;
	SNode *tmp = s->top;
	s->top = tmp->next;
	free(tmp);
	return x;
}

//栈的应用
//数制的转换
void decimalConversion(Stack *s, int n, int base){
	//n表示输入的十进制数，base表示要转换成的进制
	assert(!StackEmpty(s));
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