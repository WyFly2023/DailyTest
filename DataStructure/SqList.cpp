#include <iostream>
using namespace std;

typedef int ElemType;
#define MaxSize 30

class SqList
{
public:

    //打印
    void SqListPrint()
    {
        for(int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }

    //尾插
    void SqListPushBack(ElemType x)
    {
        if(size == MaxSize)
            return;
        data[size++] = x ;
    }


    //头插
    void SqListPushFront(ElemType x)
    {
        if(size == MaxSize)
            return;
        for(int i = size - 1; i >= 0; --i)
        {
           data[i + 1] = data[i];
        }
        data[0] = x;
        size++;
    }

    //头删
    void SqListPopFront(){
        for(int i = 0; i < size; i++)
            data[i] = data[i + 1];
        size--;
    }

    //尾删
    void SqListPopBack()
    {
        if(size > 0)
            size--;
    }

    // 顺序表查找
    int SqListFind(ElemType x)
    {
        for(int i = 0; i < size; ++i)
        {
            if(data[i] == x)
                return i;
        }
        return -1;
    }

    // 顺序表在pos位置插入x
    void SqListInsert(int pos, ElemType x)
    {
        if(size == MaxSize)
            return;
        if(pos < 0 || pos > size + 1)
            return;
        for(int i = size - 1; i >= pos - 1; i--)
            data[i + 1] = data[i];
        data[pos - 1] = x;
        size++;
    }

    // 顺序表删除pos位置的值
    void SqListErase(int pos)
    {
        if(pos <= 0 || pos > size)
            return;
        for(int i = pos - 1; i < size; i++)
            data[i - 1] = data[i];
        size--;
    }

    SqList(){
        size = 0;
    }
    ElemType data[MaxSize];
    int size;
};

int main()
{
    SqList L;
    L.SqListPushBack(1);
    L.SqListPushBack(2);

    L.SqListPrint();

    return 0;
}
