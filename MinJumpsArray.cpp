int Solution::jump(vector<int> &A) {
    if(A.size()==1) return 0;
    if(A[0]==0) return -1;
    int start=0, end=0, limit=0;
    int count=0;
    int n = A.size();
    while(end<n-1)
    {
        count++;
        for(int i=start; i<=end; i++)
            limit = max(limit, i+A[i]);
        start = end+1;
        end = limit;
        
        if(limit==0) return -1;
    }
    return count;
    
}
