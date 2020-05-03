vector<int> Solution::solve(vector<vector<int> > &A) {
    vector<int> ans;
    unordered_map<int,int> freq_map;
    unordered_map<int, stack<int>> freq_stack;
    int max_freq = 0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i][0]==1)
        {
            int freq = ++freq_map[A[i][1]];
            freq_stack[freq].push(A[i][1]);
            max_freq = max(max_freq,freq);
            ans.push_back(-1);
            
        }
        else
        {
            int x = freq_stack[max_freq].top();
            freq_stack[max_freq].pop();
            freq_map[x]--;
            ans.push_back(x);
            if(freq_stack[max_freq].empty())
            {
                max_freq--;
            }
        }
    }
    
    
    
    return ans;
}
