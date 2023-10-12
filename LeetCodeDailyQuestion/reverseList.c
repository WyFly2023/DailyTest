

//206. 反转链表


LNode *reverseList(LNode *L)
{
    if (L == NULL)
        return L;
    LNode *cur = L;
    LNode *next = NULL;
    LNode *prev = NULL;
    while (cur != NULL)
    {
        next = cur->next; // 保存下一个节点
        cur->next = prev; // 指向前一个节点

        // 更新节点
        prev = cur;
        cur = next;
    }

    return prev;
}