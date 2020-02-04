void func(vector<int> A, int i, vector<vector<int> > &res)
{
    
    if(i>=(A.size()))
    {
        res.push_back(A);
        return;
    }
    for(int j=i;j<A.size();j++)
    {
        if(j!=i and A[i]==A[j]) continue;
        swap(A[i],A[j]);
        func(A,i+1,res);
    }
    
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    sort(A.begin(),A.end());
    vector<vector<int> > res;
    func(A,0,res);
    return res;
}
