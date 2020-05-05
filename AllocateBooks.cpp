bool func(vector<int> &A,int B, int mid)
{
    int i=0;
    int sum = mid;
    int cnt = 1;
    while(i<A.size())
    {
        if(sum-A[i]<0)
        {
            cnt++;
            sum = mid;
        }
        else
        {
            sum = sum - A[i];
            i++;
        }
        if(cnt>B) return false;
    }
    return true;
}
int Solution::books(vector<int> &A, int B) {
    int n = A.size();
    if(n<B) return -1;
    int low = 1;
    int high = 0;
    for(int i=0;i<n;i++)
    {
        high = high + A[i];
    }
    int ans = INT_MAX;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        if(func(A,B,mid))
        {
            ans = min(ans,mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        
    }
    return ans;
    
}


