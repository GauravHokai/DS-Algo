int Solution::longestConsecutive(const vector<int> &A) {
    if(A.size()==1) return 1;
    unordered_set<int> s;
    for(auto i:A)
    {
        s.insert(i);
    }
    int res = 0;
    for(auto i:s)
    {
        if(s.find(i-1)==s.end())
        {
            int x = i+1;
            //cout<<x<<endl;
            while(s.find(x)!=s.end())
            {
                x = x + 1;
            }
            res = max(res,x-i);
            
        }
    }
    return res;
}
