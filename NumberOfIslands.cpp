void solveit(vector<vector<int>> &A, vector<int> &visited,int i, int j,int rows,int cols)
{
    
    if(i<0||i>=rows||j<0||j>=cols) return;
    if(visited[i*cols + j]==1) return;
    if(A[i][j]==0)return;
    visited[i*cols + j] = 1;
    solveit(A,visited,i-1,j,rows,cols);
    solveit(A,visited,i,j-1,rows,cols);
    solveit(A,visited,i+1,j,rows,cols);
    solveit(A,visited,i,j+1,rows,cols);
    solveit(A,visited,i-1,j-1,rows,cols);
    solveit(A,visited,i+1,j+1,rows,cols);
    solveit(A,visited,i-1,j+1,rows,cols);
    solveit(A,visited,i+1,j-1,rows,cols);
}

int Solution::solve(vector<vector<int> > &A) {
    int rows = A.size();
    int cols = A[0].size();
    int ans = 0;
    vector<int> visited(rows*cols,0);
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(A[i][j]==1 and visited[i*cols + j]==0)
            {
                solveit(A,visited,i,j,rows,cols);
                ans++;
            }
        }
    }
    return ans;
}
