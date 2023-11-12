#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElemType;
typedef struct SL{
    ElemType * data;
    int size;
    int capacity;
}SL;

void CheckCapacity(SL *ps){
    if(ps->size == ps->capacity){
        int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        ElemType *tmp = (ElemType*)realloc(ps->data, sizeof(ElemType) * newCapacity);
        if(tmp != NULL){
            ps->data = tmp;
            ps->capacity = newCapacity;
        }
    }
}

void SLInit(SL* ps){
    ps->data = NULL;
    ps->capacity = ps->size = 0;
}

void SLDestroy(SL* ps){
    free(ps->data);
    ps->data = NULL;
    ps->size = 0;
    ps->capacity = 0;
}

void SLPrint(SL* ps){
    for(int i = 0; i < ps->size; i++)
        printf("%d ",ps->data[i]);
    printf("\n");
}

void SLPushBack(SL* ps, ElemType x){
    CheckCapacity(ps);
    ps->data[ps->size++] = x;
}

void SLPushFront(SL* ps, ElemType x){
    CheckCapacity(ps);
    for(int i = ps->size - 1; i >= 0; i--)
        ps->data[i + 1] = ps->data[i];
    ps->data[0] = x;
    ps->size++;
}

void SLPopFront(SL* ps){
    assert(ps->size > 0);
    for(int i = 0; i < ps->size; i++)
        ps->data[i] = ps->data[i + 1];
    ps->size--;
}
void SLPopBack(SL* ps){
    assert(ps->size > 0);
    ps->size--;
}

// 顺序表查找
int SLFind(SL* ps, ElemType x){
    int index = -1;
    for(int i = 0; i < ps->size; i++){
        if(ps->data[i] == x)
            index = i;
    }
    return index;
}

// 顺序表在pos位置插入x
void SLInsert(SL* ps, int pos, ElemType x){
    if(pos <= 0 || pos > ps->size + 1){
        printf("插入位置有误！\n");
        exit(-1);
    }
    CheckCapacity(ps);
    for(int i = ps->size - 1; i >= pos - 1; i--)
        ps->data[i + 1] = ps->data[i];
    ps->data[pos - 1] = x;
    ps->size++;
}
// 顺序表删除pos位置的值
void SLErase(SL* ps, int pos){
    assert(ps->size > 0);
    if(pos > ps->size || pos <= 0){
        printf("删除位置有误！\n");
        exit(-1);
    }
    for(int i = pos - 1; i < ps->size; i++)
        ps->data[i - 1] = ps->data[i];
    ps->size--;
}


int main() {

    SL s;
    SLInit(&s);
    SLPushBack(&s,1);
    SLPushBack(&s,2);
    SLPushBack(&s,3);
    SLPrint(&s);


    SLDestroy(&s);
    return 0;
}
