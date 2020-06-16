void func(int x, int y, int cnt, vector<vector<int>> &A,int &res)
{
    if(x<0 or x>=A.size() or y<0 or y>=A[0].size() or A[x][y]<0) return;
    if(A[x][y]==2 and cnt==0)
    {
        res++;
        return;
    }
    if(A[x][y]==2) return;
    A[x][y] = -2;
    cnt--;
    func(x+1,y,cnt,A,res);
    func(x-1,y,cnt,A,res);
    func(x,y+1,cnt,A,res);
    func(x,y-1,cnt,A,res);
    A[x][y]=0;
    cnt++;
}
int Solution::solve(vector<vector<int> > &A) {
    int s_x,s_y,cnt = 1,res = 0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            if(A[i][j]==0) cnt++;
            if(A[i][j]==1)
            {
                s_x = i;
                s_y = j;
            }
        }
    }
    func(s_x,s_y,cnt,A,res);
    return res;
}
