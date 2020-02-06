void func(vector<int> &A,int tg,int cs,int i, set<vector<int> > &result, vector<int> aux)
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
    func(A,tg,cs+A[i],i+1,result,temp);
    func(A,tg,cs,i+1,result,aux);
    
    
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(),A.end());
    set<vector<int> > result;
    vector<int> aux;
    func(A,B,0,0,result,aux);
    vector<vector<int> > ans;
    for(auto ch:result)
    {
        ans.push_back(ch);
    }
    return ans;
}
