/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *reverse(ListNode *head, int n)
{
    ListNode *curr = head;
    ListNode *prev = NULL;
    ListNode *next = NULL;
    int count = 0;
    while(curr!=NULL and count<n)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next!=NULL)
    {
        head->next = reverse(next,n);
    }
    return prev;
    
    
}
ListNode* Solution::reverseList(ListNode* A, int B) {
    A = reverse(A,B);
    return A;
    
}
