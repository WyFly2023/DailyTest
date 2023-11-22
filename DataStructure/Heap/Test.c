#include "Heap.h"

int main() {

    int arr[] = {2,54,23,56,1,9,5,3,2,45};
    Heap hp;
    HeapInit(&hp);
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]);i++){
        HeapPush(&hp,arr[i]);
    }
    while(!HeapEmpty(&hp)){
        printf("%d ", HeapTop(&hp));
        HeapPop(&hp);
    }
    return 0;
}
