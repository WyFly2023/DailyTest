/*
循环队列的基本操作
*/

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#define MaxSize 10

typedef int ElemType;
typedef struct Queue{
    ElemType data[MaxSize];
    int front;
    int rear;
}Queue;

//初始化
void initQueue(Queue *queue){
    queue->front = 0;
    queue->rear = 0;
}

//判满
bool isFull(Queue* queue){
    if((queue->rear + 1) % MaxSize == queue->front)
        return true;
    return false;
}

//判空
bool isEmpty(Queue* queue){
    if(queue->front == queue->rear)
        return true;
    return false;
}

//入队
void Enqueue(Queue* queue, ElemType e){
    assert(!isFull(queue));
    queue->data[queue->rear] = e;
    queue->rear = (queue->rear + 1) % MaxSize;
}

//出队
ElemType deQueue(Queue *queue){
    assert(!isEmpty(queue));
    ElemType x = queue->data[queue->front];
    queue->front = (queue->front + 1) % MaxSize;
    return x;
}

//
void printQueue(Queue* queue){
    assert(queue);
    /*
    int i = queue->front;
    while(i != queue->rear){
        printf("%d ",queue->data[i]);
        i = (i + 1) % MaxSize;
    }
    printf("\n");
    */
    while(queue->front != queue->rear){
        printf("%d ", deQueue(queue));
    }
    printf("\n");
}

int main() {
    Queue queue;
    initQueue(&queue);
    Enqueue(&queue,1);
    Enqueue(&queue,2);
    Enqueue(&queue,3);
    Enqueue(&queue,4);
    deQueue(&queue);
    printQueue(&queue);
    return 0;
}
