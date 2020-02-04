void func(vector<int> &A,int i, vector<int> aux,vector<vector<int> > &result, bool flag)
{
    if(flag)
        result.push_back(aux);
    if(i==A.size())
        return;
    vector<int> temp(aux);
    temp.push_back(A[i]);
    func(A,i+1,temp,result,1);
    func(A,i+1,aux,result,0);
    
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(),A.end());
    vector<vector<int> > result;
    vector<int> aux;
    func(A,0,aux,result,1);
    return result;
}
