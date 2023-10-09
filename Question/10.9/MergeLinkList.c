 /*

 \* 21.合并两个有序链表

 *

 \*  将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

  

  if(list1 == NULL)

​    return list2;

  else if(list2 == NULL)

​    return list1;

  struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));   

  struct ListNode* cur = dummy;

  while(list1 != NULL && list2 != NULL)

  {

​    if(list1->val <= list2->val)

​    {

​      cur->next = list1;

​      list1 = list1->next;

​    }

​    else

​    {

​      cur->next = list2;

​      list2 = list2->next;

​    }

​    cur = cur->next;

  }

  if(list1 != NULL)

​    cur->next = list1;

  if(list2 != NULL)

​    cur->next = list2;

  struct ListNode* phead = dummy->next;

  free(dummy);

  return phead;

}

