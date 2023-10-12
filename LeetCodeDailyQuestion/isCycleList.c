/*
 *	
 *	LeetCode 141. 环形链表
 *
*/

bool hasCycle(struct ListNode *head) {
    if(head == NULL||head->next == NULL)
        return false;
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while(slow != fast)
    {
        if(fast == NULL || fast->next == NULL)
            return false;
        else
        {
            fast = fast->next->next;
            slow = slow->next;
        } 
    }
    return true;
}