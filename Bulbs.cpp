//got through the toggle logic
int Solution::bulbs(vector<int> &A) {
    int ans = 0;
    bool toggle = 0;
    for(int i=0;i<A.size();i++)
    {
        if(toggle) A[i] = 1 - A[i];
        if(A[i]==0)
        {
            A[i]=1;
            ans++;
            if(toggle)
            {
                toggle = 0;
            }
            else
            {
                toggle = 1;
            }
        }
    }
    return ans;
}
