//try given solution approach
int Solution::trap(const vector<int> &A) {
    vector<int> left(A.size(),0);
    vector<int> right(A.size(),0);
    int left_max = INT_MIN;
    for(int i=1;i<A.size();i++)
    {
        left_max = max(left_max,A[i-1]);
        left[i] = left_max;
    }
    int right_max = INT_MIN;
    for(int i=A.size()-2;i>=0;i--)
    {
        right_max = max(right_max,A[i+1]);
        right[i] = right_max;
    }
    int ans = 0;
    for(int i=0;i<A.size();i++)
    {
        int x = min(right[i],left[i]) - A[i];
        if(x>0)
        {
            ans = ans + x;
        }
    }
    return ans;
}
