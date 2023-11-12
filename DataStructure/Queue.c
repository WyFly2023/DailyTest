//
// Created by wyf on 2023/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int ElemType;
//定义节点结构体
typedef struct QNode{
    ElemType data;
    struct QNode * next;
}QNode;

//定义队列结构体
typedef struct Queue{
    QNode * front;
    QNode * rear;
}Queue;

//初始化
void InitQueue(Queue* q){
    q->rear = NULL;
    q->front = NULL;
}

//判空
bool QueueEmpty(Queue *q){
    return q->front == NULL;
}

//申请节点
QNode * ApplyNode(ElemType e){
    QNode *newNode = (QNode*)malloc(sizeof(QNode));
    if(newNode != NULL){
        newNode->data = e;
        newNode->next = NULL;
    }
    return newNode;
}

//入队
void EnQueue(Queue *q, ElemType e){
    QNode *newNode = ApplyNode(e);
    if(q->front == NULL){
        q->front = newNode;
        q->rear = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

//出队
ElemType DeQueue(Queue *q){
    assert(!QueueEmpty(q));
    QNode * tmp = q->front;
    ElemType x = q->front->data;
    q->front = tmp->next;
    free(tmp);
    return x;
}

//打印
void printQueue(Queue* q){
    while(q->front != NULL){
        printf("%d ",DeQueue(q));
    }
}

int main(){
    Queue queue;
    InitQueue(&queue);

    return 0;
}