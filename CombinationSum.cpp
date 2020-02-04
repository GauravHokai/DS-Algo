void func(vector<int> &A,int i,int cs, int tg,set<vector<int> > &result, vector<int> &aux)
{
    if(cs>tg) return;
    if(i==A.size())
    {
        if(cs==tg)
        {
            result.insert(aux);
            return;
        }
        return;
    }
    vector<int> temp(aux);
    temp.push_back(A[i]);
    func(A,i,cs+A[i],tg, result,temp);
    func(A,i+1,cs,tg,result,aux);
    
    
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    set<vector<int> > result;
    sort(A.begin(),A.end());
    vector<int> aux;
    func(A,0,0,B,result,aux);
    vector<vector<int> >ans;
    for(auto i:result)
    {
        ans.push_back(i);
    }
    return ans;
}
