/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *ptr = A;
    ListNode head(INT_MIN);
    ListNode *pt = &head;
    
    unordered_set<int> s;
    while(ptr!=NULL)
    {
        if(s.find(ptr->val)==s.end())
        {
            s.insert(ptr->val);
            pt->next = ptr;
            pt = ptr;
        }
        ptr = ptr->next;
    }
    pt->next = NULL;
    return head.next;
}
