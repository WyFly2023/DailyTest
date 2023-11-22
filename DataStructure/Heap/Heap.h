//
// Created by wyf on 2023/11/22.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

#endif //HEAP_HEAP_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct Heap{
    ElemType *data;
    size_t capacity;
    size_t size;
}Heap;

void HeapInit(Heap *pH);
void HeapDestroy(Heap *pH);
void HeapPush(Heap *pH, ElemType e);
void HeapPop(Heap *pH);
ElemType HeapTop(Heap *pH);
bool HeapEmpty(Heap *pH);
size_t HeapSize(Heap *pH);
