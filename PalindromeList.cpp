/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *reverse(ListNode *ptr)
{
    ListNode *curr = ptr;
    ListNode *nxt, *prev = NULL;
    while(curr)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
int Solution::lPalin(ListNode* A) {
    ListNode *fast = A;
    ListNode *slow = A;
    ListNode *pre = slow;
    while(fast and fast->next)
    {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = NULL;
    ListNode *temp = reverse(slow);
    pre = A;
    while(temp and pre)
    {
        if(temp->val != pre->val)
        {
            return 0;
        }
        temp = temp->next;
        pre = pre->next;
    }
    return 1;
}




