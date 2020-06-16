#define mod 10000003
bool func(int A,vector<int> &C,int mid)
{
    int i=0;
    int sum = 0;
    int cnt = 1;
    while(i<C.size())
    {
        sum = (sum + C[i]);
        if(sum>mid)
        {
            cnt++;
            sum = 0;
        }
        else
        {
            i++;
        }
        if(cnt>A) return false;
    }
    return true;
}
int Solution::paint(int A, int B, vector<int> &C) {
    int ans;
    int low = 1;
    int high = 0;
    for(int i=0;i<C.size();i++)
    {
        high =(high + C[i]);
    }
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(func(A,C,mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return (ans*(long long) B)%mod;
}
