int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    int arr[m][n];
    if(A[m-1][n-1]==1) return 0;
    if(A[0][0]==1)
        return 0;
    else
        arr[0][0] = 1;
    for(int i=1;i<m;i++)
    {
        if(arr[i-1][0]==1 and A[i][0]==0)
            arr[i][0] = 1;
        else
            arr[i][0] = 0;
    }
    for(int i=1;i<n;i++)
    {
        if(arr[0][i-1]==1 and A[0][i]==0)
            arr[0][i] = 1;
        else
            arr[0][i] = 0;
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(A[i][j]!=1)
            {
                arr[i][j] = arr[i-1][j]+arr[i][j-1];
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }
    return arr[m-1][n-1];
    
    
}
