#include <iostream>
using namespace std;
typedef int ElemType;
class LNode{
public:
    ElemType data;
    LNode *next;
    LNode(ElemType data){
        this->data = data;
        next = nullptr;
    }
};
class LinkList{
private:
    LNode* head;
public:
    LinkList() {
        head = nullptr;
    }

    // 单链表打印
    void SListPrint()const{
        auto cur = head;
        while(cur != nullptr)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    
    // 单链表尾插
    void SListPushBack( ElemType x){
        auto newNode = new LNode(x);
        if(head == nullptr)
            head = newNode;
        else{
            auto cur = head;
            while(cur->next != nullptr){
                cur = cur->next;
            }
            cur->next = newNode;
        }
    }
    
    // 单链表的头插
    void SListPushFront(ElemType x){
        auto newNode = new LNode(x);
        newNode->next = head;
        head = newNode;
    }
    // 单链表的尾删
    void SListPopBack(){
        if(head == nullptr){
            cout << "List is Empty!";
            return;
        }
        else if(head->next == nullptr)
            head = nullptr;
        else{
            auto cur = head;
            while(cur->next->next != nullptr){
                cur = cur->next;
            }
            auto tmp = cur->next;
            cur->next = nullptr;
            delete tmp;
        }
    }

    // 单链表头删
    void SListPopFront(){
        if(head == nullptr){
            cout << "List is empty!";
            return;
        }
        auto next = head->next;
        delete head;
        head = next;
    }
    // 单链表查找
    LNode* SListFind(ElemType x){
        auto cur = head;
        while(cur != nullptr)
        {
            if(cur->data == x)
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    // 单链表在pos位置之后插入x
    // 分析思考为什么不在pos位置之前插入？
    //在pos之前插需要遍历找到pos的直接前驱时间复杂度为O(n)，效率低，
    // 而在pos之后插如时间复杂度为O(1)更加高效
    void SListInsertAfter(LNode* pos, ElemType x){
        if(pos== nullptr)
            return;
        auto newNode = new LNode(x);
        newNode->next = pos->next;
        pos->next = newNode;
    }

    // 单链表删除pos位置之后的值
    // 分析思考为什么不删除pos位置？
    //删除pos位置同样需要遍历需要O(n)时间复杂度，而删除pos之后则只需要O(1)
    void SListEraseAfter(LNode* pos){
        if(pos == nullptr || pos->next == nullptr)
            return;
        auto tmp = pos->next;
        pos->next = tmp->next;
        delete tmp;
    }

    // 在pos的前面插入
    void SLTInsert(LNode* pos, ElemType x){
        if(pos==head)
            SListPushFront(x);//如果pos为头节点直接调用头插法
        else{
            auto cur = head;
            while(cur->next != pos){
                cur = cur->next;
            }
            auto newNode = new LNode(x);
            newNode->next = pos;
            cur->next = newNode;
        }
    }

    // 删除pos位置
    void SLTErase(LNode* pos){
        if(pos == nullptr)
            return;
        if(head == pos){
            SListPopFront();
        }
        else
        {
            auto prev = head;
            while(prev->next != pos){
                prev = prev->next;
            }
            prev->next = pos->next;
            delete pos;
            pos = nullptr;
        }
    }

    void SLTDestroy(){
        auto cur = head;
        while(cur != nullptr){
            auto tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        head = nullptr;
    }
};

void Test01(){
    LinkList L;
    L.SListPushBack(1);
    L.SListPushBack(2);
    L.SListPushBack(3);
    L.SListPushBack(4);
    auto r = L.SListFind(4);
    L.SListEraseAfter(r);

    L.SListPrint();
    L.SLTDestroy();
}

void Test02(){
    LinkList L;
   L.SListPushFront(1);
   L.SListPushFront(2);
   L.SListPushFront(3);
   L.SListPushFront(4);
   L.SListPushFront(5);
   auto ret = L.SListFind(1);
   L.SListInsertAfter(ret,6);
   L.SListPrint();
   L.SLTDestroy();
}

void Test03()
{
    LinkList L;
    L.SListPushBack(5);
    L.SListPushBack(6);
    L.SListPushBack(7);
    L.SListPushBack(8);
    auto r = L.SListFind(8);

    L.SLTErase(r);
    L.SListPrint();
    L.SLTDestroy();
}
int main() {
    //Test01();
    //Test02();
    Test03();
    return 0;
}
