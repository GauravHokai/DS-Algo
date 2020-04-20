struct TrieNode{
    char ch;
    int freq = 0;
    bool isTerminal = false;
    unordered_map<char,TrieNode*> child;
    TrieNode(char c)
    {
        ch = c;
    }
};

void addnode(string str, TrieNode *root)
{
    if(str.length()==0) return;
    TrieNode *temp = root;
    for(int i=0;i<str.length();i++)
    {
        if(temp->child.find(str[i])!=temp->child.end())
        {
            temp = temp->child[str[i]];
        }
        else
        {
            TrieNode *node = new TrieNode(str[i]);
            temp->child.insert({str[i],node});
            temp = temp->child[str[i]];
        }
        temp->freq++;
    }
    temp->isTerminal = true;
    return;
}

string func(string str, TrieNode *root)
{
    TrieNode *temp = root;
    string ans = "";
    for(int i=0;i<str.length();i++)
    {
        if(temp->child.find(str[i])==temp->child.end())
        {
            return "";
        }
        else
        {
           if(temp->freq==1)
            {
                return ans;
            }
            else{
                ans+=str[i];
            }
            temp = temp->child[str[i]];
        }
        
    }
    return ans;
    
}
vector<string> Solution::prefix(vector<string> &A) {
    TrieNode *root = new TrieNode(NULL);
    vector<string> ans;
    for(int i=0;i<A.size();i++)
    {
        addnode(A[i],root);
    }
    for(int i=0;i<A.size();i++)
    {
        string str = func(A[i],root);
        ans.push_back(str);
    }
    return ans;
}
