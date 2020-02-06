int Solution::minPathSum(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    int result[m][n];
    result[0][0] = A[0][0];
    for(int i=1;i<n;i++)
    {
        result[0][i] = result[0][i-1] + A[0][i];
    }
    for(int i=1;i<m;i++)
    {
        result[i][0] = result[i-1][0] + A[i][0];
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            result[i][j] = min(result[i-1][j],result[i][j-1]) + A[i][j];
        }
    }
    /*for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    */
    
    return result[m-1][n-1];
    
    
}
