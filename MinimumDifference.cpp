int search(int low, int high,int val,vector<int> temp)
{
    int mid;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(temp[mid]<val)
            low = mid + 1;
        else
            high = mid-1;
    }
    return mid;
}
int Solution::solve(int A, int B, vector<vector<int> > &C) {
    for(int i=0;i<A;i++)
    {
        sort(C[i].begin(),C[i].end());
    }
    int ans = INT_MAX;
    for(int i=0;i<A-1;i++)
    {
        for(int j=0;j<B;j++)
        {
            int index = search(0,B-1,C[i][j],C[i+1]);
            ans = min(ans,abs(C[i][j]-C[i+1][index]));
            if(index-1>=0)
                ans = min(ans,abs(C[i][j]-C[i+1][index-1]));
            
        }
    }
    return ans;
}
