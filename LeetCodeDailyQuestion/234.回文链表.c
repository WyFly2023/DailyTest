/*
 * @lc app=leetcode.cn id=234 lang=c
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverseList(struct ListNode *head)
{
    if (head == NULL)
        return NULL;
    struct ListNode *cur = head;
    struct ListNode *next = NULL;
    struct ListNode *prev = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;

        prev = cur;
        cur = next;
    }

    return prev;
}

bool isPalindrome(struct ListNode *head)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;

    // 找中间节点
    // 当fast->next == NULL时slow则为中间节点
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow = reverseList(slow);

    while (slow != NULL)
    {
        if (slow->val != head->val)
            return false;
        else
        {
            head = head->next;
            slow = slow->next;
        }
    }
    return true;
}
// @lc code=end
