/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    if(A==NULL) return;
    queue<TreeLinkNode*> q;
    q.push(A);
    while(!q.empty())
    {
        int n = q.size();
        for(int i=0;i<n;i++)
        {
            TreeLinkNode *node = q.front();
            q.pop();
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
            if(i+1<n)
            {
                node->next = q.front();
            }
            else
            {
                node->next = NULL;
            }
        }
    }
    
}
