/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *func(ListNode *A, ListNode *B)
{
    if(A==NULL) return B;
    if(B==NULL) return A;
    ListNode *head = NULL;
    if(A->val<B->val)
    {
        head = A;
        head->next = func(A->next,B);
    }
    else
    {
        head = B;
        head->next = func(A,B->next);
    }
    return head;
     
}
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode *head = A[0];
    for(int i=1;i<A.size();i++)
    {
        head = func(head,A[i]);
    }
    return head;
}
