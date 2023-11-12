#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElemType;

typedef struct ListNode{
    struct ListNode *next;
    struct ListNode *prev;
    ElemType val;
}ListNode;

//申请节点
ListNode *ApplyNode(ElemType val){
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    if(newNode != NULL){
        newNode->prev = NULL;
        newNode->next = NULL;
        newNode->val = val;
        return newNode;
    }
}
//初始化
ListNode* InitList(){
    ListNode *pHead = (ListNode*)malloc(sizeof(ListNode));
    pHead->next = pHead;
    pHead->prev = pHead;
}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, ElemType val){
    assert(pos);
    ListNode *newNode = ApplyNode(val);
    newNode->next = pos;
    newNode->prev = pos->prev;

    pos->prev->next = newNode;
    pos->prev = newNode;
}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos){
    assert(pos);

    pos->next->prev = pos->prev;
    pos->prev->next = pos->next;
    free(pos);
}

//双向链表尾插
void PushBack(ListNode* pHead, ElemType val){
    assert(pHead);
    /*  1.正常实现
    ListNode *tail = pHead->prev;
    ListNode *newNode = ApplyNode(val);

    tail->next = newNode;
    newNode->prev = tail;
    pHead->prev = newNode;
    newNode->next = pHead;
    */
    //2.调用pos位置之前插入方法来实现尾插
    ListInsert(pHead,val);
}

//双向链表尾删
void PopBack(ListNode* pHead){
    assert(pHead);
    assert(pHead->next != pHead);
/*
    ListNode *tail = pHead->prev;
    ListNode *tailPrev = tail->prev;

    tailPrev->next = pHead;
    pHead->prev = tailPrev;

    free(tail);
*/
    //调用pos位置删除方法
    ListErase(pHead->prev);
}
//双向链表打印
void PrintList(ListNode* pHead){
    ListNode *cur = pHead->next;
    while(cur != pHead){
        printf("%d ",cur->val);
        cur = cur->next;
    }
    printf("\n");
}
// 双向链表销毁
void ListDestroy(ListNode* pHead){
    ListNode * cur = pHead->next;
    while(cur != pHead){
        ListNode *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(pHead);
}

// 双向链表头插
void PushFront(ListNode* pHead, ElemType val){
    assert(pHead);
    /* 1.正常实现
    ListNode *newNode = ApplyNode(val);

    newNode->next = pHead->next;
    pHead->next->prev = newNode;

    newNode->prev = pHead;
    pHead->next = newNode;
    */

    //2.调用pos位置之前插入方法来实现头插
    ListInsert(pHead->next,val);
}

// 双向链表头删
void PopFront(ListNode* pHead){
    assert(pHead);
    assert(pHead->next != pHead);
/*
    ListNode *tmp = pHead->next;
    pHead->next = tmp->next;
    tmp->next->prev = pHead;

    free(tmp);
*/
    //调用删除pos位置方法
    ListErase(pHead->next);
}

// 双向链表查找
ListNode* ListFind(ListNode* pHead, ElemType val){
    assert(pHead);
    ListNode * cur = pHead->next;
    while(cur != pHead){
        if(cur->val == val){
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

int main() {

    ListNode * L = InitList();

    PushBack(L,4);
    PushBack(L,5);
    PushBack(L,6);

    PrintList(L);

    ListDestroy(L);
    L = NULL;
    return 0;
}
