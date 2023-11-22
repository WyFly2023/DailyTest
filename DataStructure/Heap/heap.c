//
// Created by wyf on 2023/11/22.
//

#include "Heap.h"


void HeapInit(Heap *pH){
    pH->data = NULL;
    pH->capacity = 0;
    pH->size = 0;
}

void HeapDestroy(Heap *pH){
    free(pH->data);
    pH->data = NULL;
    pH->size = pH->capacity = 0;
}

//交换
static void swap(ElemType *e1, ElemType *e2){
    ElemType tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
}

//向上调整
static void AdjustUp(ElemType* data,size_t child){
    size_t parent = (child - 1) / 2;
    while(child > 0){
        if(data[child] < data[parent]){
            swap(&data[child], &data[parent]);
            child = parent;
            parent = (parent - 1)/2;
        }
        else{
            break;
        }
    }
}

void HeapPush(Heap *pH, ElemType e){
    assert(pH);
    if(pH->size == pH->capacity){
        size_t newCapacity = pH->capacity == 0 ? 4 : pH->capacity * 2;
        ElemType *tmp = (ElemType*)realloc(pH->data,sizeof(ElemType) * newCapacity);
        if(tmp){
            pH->data = tmp;
            pH->capacity = newCapacity;
        }
    }
    pH->data[pH->size++] = e;
    AdjustUp(pH->data,pH->size - 1);
}

void AdjustDown(ElemType* data,size_t size, size_t parent){
    size_t child = parent * 2 + 1;
    while(child < size){
        if(child + 1 < size && data[child] > data[child + 1]){
            child++;
        }
        if(data[child] < data[parent]){
            swap(&data[child], &data[parent]);
            parent = child;
            child = child * 2 + 1;
        }
        else{
            break;
        }
    }
}
void HeapPop(Heap *pH){
    assert(pH);
    assert(!HeapEmpty(pH));
    swap(&pH->data[0], &pH->data[pH->size -1]);
    pH->size--;
    AdjustDown(pH->data,pH->size, 0);
}

ElemType HeapTop(Heap *pH){
    assert(pH);
 return pH->data[0];
}

bool HeapEmpty(Heap *pH){
    assert(pH);
    return pH->size == 0;
}

size_t HeapSize(Heap *pH){
    return pH->size;
}