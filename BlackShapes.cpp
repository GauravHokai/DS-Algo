void dfs(vector<string> &v,int i, int j)
{
    if(i>=v.size()||j>=v[i].size()||i<0||j<0) return;
    if(v[i][j]!='X') return;
    v[i][j]='O';
    dfs(v,i+1,j);
    dfs(v,i,j+1);
    dfs(v,i,j-1);
    dfs(v,i-1,j);
    
}
int Solution::black(vector<string> &A) {
    vector<string>v = A;
    int ans = 0;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(v[i][j]=='X')
            {
                dfs(v,i,j);
                ans++;
            }
        }
    }
    return ans;
}
