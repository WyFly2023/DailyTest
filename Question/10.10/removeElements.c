struct ListNode* removeElements(struct ListNode* head, int val){
    if(head == NULL)
        return NULL;
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    while(cur != NULL)
    {
        if(cur->val == val){
            if(cur == head){
                head = cur->next;
                free(cur);
                cur = head;
            }
            else{
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            } 
        }
        else{
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}