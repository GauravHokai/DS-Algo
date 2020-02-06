void func(vector<int> &A,int i, vector<int> aux,set<vector<int> > &result, bool flag)
{
    if(flag)
        result.insert(aux);
    if(i==A.size())
        return;
    vector<int> temp(aux);
    temp.push_back(A[i]);
    func(A,i+1,temp,result,1);
    func(A,i+1,aux,result,0);
    
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(),A.end());
    set<vector<int> > result;
    vector<int> aux;
    func(A,0,aux,result,1);
    vector<vector<int> > ans;
    for(auto ch:result)
    {
        ans.push_back(ch);
    }
    
    return ans;
}
