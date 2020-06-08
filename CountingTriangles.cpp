#define mod 1000000007
int Solution::nTriang(vector<int> &A) {
    sort(A.begin(),A.end());
    int ans = 0;
    for(int i=A.size()-1;i>=0;i--)
    {
        int l=0,h = i-1;
        while(l<h)
        {
            if(A[l]+A[h]>A[i])
            {
                int x = h-l;
                ans = (ans + x)%mod;
                h--;
            }
            else
                l++;
        }
    }
    
    
    return ans;
    
}
