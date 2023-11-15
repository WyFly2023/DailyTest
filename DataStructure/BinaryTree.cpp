#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef char ElemType;
class BTNode{
public:
    BTNode(ElemType val){
        this->val = val;
        lChild = nullptr;
        rChild = nullptr;
    }
    ElemType val;
    BTNode *lChild;
    BTNode *rChild;
};

class BiTree{
public:
    //创建二叉树
    void CreateBiTree(){
        root = CreatBinaryTree();
    }

    //遍历二叉树
    void PreOrder(){
        cout << "前序遍历结果: ";
        FrontPreOrder(root);
        cout << endl;

        cout << "中序遍历结果: ";
        MidPreOrder(root);
        cout << endl;

        cout << "后序遍历结果: ";
        AfterPreOrder(root);
        cout << endl;

        cout << "使用栈前序遍历:";
        vector<ElemType> ret = Preorder(root);
        for (ElemType val : ret)
            cout << val << " ";
        cout << endl;

    }
private:
    BTNode* CreatBinaryTree(){
        char ch;
        cout << "节点数据(输入#代表空节点):" << endl;
        cin >> ch;
        if(ch == '#')
            return nullptr;
        BTNode * newNode = new BTNode(ch);
        cout << "节点"<< ch << "的lChild: ";
        newNode->lChild = CreatBinaryTree();
        cout << "节点"<< ch << "的rChild: ";
        newNode->rChild = CreatBinaryTree();

        return newNode;
    }
    //前序
    void FrontPreOrder(BTNode * root){
        if(root == nullptr)
            return;
        cout << root->val << " ";
        FrontPreOrder(root->lChild);
        FrontPreOrder(root->rChild);
    }
    //中序
    void MidPreOrder(BTNode * root){
        if(root == nullptr)
            return;
        MidPreOrder(root->lChild);
        cout << root->val << " ";
        MidPreOrder(root->rChild);
    }
    //后序
    void AfterPreOrder(BTNode * root){
        if(root == nullptr)
            return;
        AfterPreOrder(root->lChild);
        AfterPreOrder(root->rChild);
        cout << root->val << " ";
    }

    //使用栈遍历二叉树
    vector<ElemType> Preorder(BTNode* root) {
        vector<ElemType> ret;  // 用于存储前序遍历结果

        if (root == nullptr) {
            return ret;  // 如果根节点为空，直接返回空vector
        }

        stack<BTNode*> nodeStack;  // 使用栈来辅助非递归实现
        nodeStack.push(root);  // 将根节点入栈

        while (!nodeStack.empty()) {
            BTNode* cur = nodeStack.top();  // 获取栈顶节点
            nodeStack.pop();  // 弹出栈顶节点

            ret.push_back(cur->val);  // 将当前节点的值添加到vector

            // 先将右孩子入栈，再将左孩子入栈，这样保证左孩子先出栈
            if (cur->rChild != nullptr) {
                nodeStack.push(cur->rChild);
            }

            if (cur->lChild != nullptr) {
                nodeStack.push(cur->lChild);
            }
        }

        return ret;  // 返回前序遍历结果的vector
    }

    BTNode *root;
};
int main() {
    BiTree tree;

    tree.CreateBiTree();
    tree.PreOrder();
    return 0;
}
