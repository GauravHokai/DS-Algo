//explanation : https://leetcode.com/problems/smallest-good-base/discuss/96589/Java-solution-with-hand-writing-explain/433857
#define ll long long int
string Solution::solve(string A)
{
    ll num = stoll(A);
    for(int i=59;i>=2;i--)
    {
        ll val = pow(2,i);
        if(val<num)
        {
            ll low = 2;
            ll high = num-1;
            while(low<=high)
            {
                ll mid = low + (high-low)/2;
                ll left = num * (mid - 1);
                ll right=1;
                for(int j=1;j<=i;j++)
                    right = right * mid;
                right--;
                if(left==right) return to_string(mid);
                else if(left>right) low = mid + 1;
                else high = mid - 1;
            }
        }
    }
    return to_string(num-1);
}
