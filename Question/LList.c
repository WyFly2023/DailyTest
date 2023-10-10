#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ELemtype;
typedef struct LNode
{
    ELemtype data;
    struct LNode *next;
} LNode;

void printList(LNode *L)
{
    LNode *cur = L;
    while (cur != NULL)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

LNode *ApplyNode(ELemtype e)
{
    LNode *newnode = (LNode *)malloc(sizeof(LNode));
    if (newnode != NULL)
    {
        newnode->data = e;
        newnode->next = NULL;
    }
    return newnode;
}

// 尾插
void InsertTail(LNode **L, ELemtype e)
{
    LNode *newnode = ApplyNode(e);
    if (*L == NULL)
        *L = newnode;
    else
    {
        LNode *cur = *L;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = newnode;
    }
}

// 头插
void InsertFront(LNode **L, ELemtype e)
{
    LNode *newnode = ApplyNode(e);

    newnode->next = *L;
    *L = newnode;
}

// 头删
void DeleteFront(LNode **L)
{
    assert(*L != NULL);
    LNode *next = (*L)->next;
    free(*L);
    *L = next;
}

// 尾删
void DeleteTail(LNode **L)
{
    assert(*L != NULL);
    LNode *cur = *L;
    if ((*L)->next == NULL)
    {
        free(*L);
        *L = NULL;
    }
    else
    {
        while (cur->next->next != NULL)
        {
            cur = cur->next;
        }
        free(cur->next);
        cur->next = NULL;
    }
}

// 查找指定元素
LNode *searchList(LNode *L, ELemtype k)
{
    LNode *cur = L;
    while (cur != NULL)
    {
        if (cur->data == k)
            return cur;
        else
            cur = cur->next;
    }

    return NULL;
}

// 在pos位置之前插入指定元素
void PosFrontInsert(LNode **L, LNode *pos, ELemtype e)
{
    if (pos == *L)
        InsertFront(&(*L), e);
    else
    {
        LNode *posPrev = *L;
        while (posPrev->next != pos)
        {
            posPrev = posPrev->next;
        }
        LNode *newnode = ApplyNode(e);
        newnode->next = pos;
        posPrev->next = newnode;
    }
}

// 在指定位置插入元素
void insertList(LNode **L, int pos, ELemtype e)
{
    if (pos < 0)
        return;
    if (pos == 1)
        InsertFront(&(*L), e);
    else
    {
        int i = 0;
        LNode *cur = *L;
        while (cur != NULL && i < pos - 1)
        {
            cur = cur->next;
            i++;
        }
        if (cur != NULL)
        {
            LNode *newnode = ApplyNode(e);
            newnode->next = cur->next;
            cur->next = newnode;
        }
    }
}

// 在pos之后插入元素
void PosAfterInsert(LNode **pos, ELemtype e)
{
    LNode *newnode = ApplyNode(e);
    newnode->next = (*pos)->next;
    (*pos)->next = newnode;
}

// 链表的销毁
void DestroyList(LNode **L)
{
    if (*L = NULL)
        return;
    LNode *cur = *L;
    while (cur != NULL)
    {
        LNode *tmp = cur;
        cur = cur->next;
        free(tmp);
        tmp = NULL;
    }
    free(*L);
    *L = NULL;
}

int main()
{
    LNode *L = NULL;
    InsertTail(&L, 1);
    InsertTail(&L, 2);
    InsertTail(&L, 3);
    InsertTail(&L, 4);
    printList(L);

    // LNode *pos = searchList(L, 2);
    // while (pos)
    // {
    //     printf("%p->%d\n", pos, pos->data);
    //     pos = searchList(pos->next, 2);
    // }

    LNode *pos = searchList(L, 4);
    if (pos != NULL)
        PosFrontInsert(&L, pos, 30);

    printList(L);

    LNode *pos2 = searchList(L, 4);
    if (pos != NULL)
        PosAfterInsert(&pos2, 999);

    printList(L);

    DestroyList(&L);
    return 0;
}