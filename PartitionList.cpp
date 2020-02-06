/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    if(A->next==NULL) return A;
    ListNode *head1= NULL;
    ListNode *head2 = NULL;
    ListNode *f1 = NULL;
    ListNode *f2 = NULL;
    ListNode *ptr = A;
    bool flag1 = false;
    bool flag2 = false;
    while(ptr!=NULL)
    {
        if(ptr->val < B and flag1==false)
        {
            head1 = ptr;
            flag1 = true;
            f1 = head1;
        }
        if(ptr->val <B and head1!=ptr)
        {
            f1->next = ptr;
            f1 = ptr;
            
        }
        if(ptr->val >= B and flag2 ==false)
        {
            head2 = ptr;
            flag2 = true;
            f2 = head2;
        }
        if(ptr->val >= B and head2!=ptr)
        {
            f2->next = ptr;
            f2 = ptr;
            
        }
        
        
        ptr = ptr->next;
    }
    if(f1)
    {
        f1->next = head2;
        A = head1;
    }
    else
    {
        f1 = head2;
        A = head2;
    }
    
    f2->next = NULL;
    
    return A;
    
}

