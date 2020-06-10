/*Maximum positivity

Problem Description

Given an array of integers A of size N.

Return maximum size subarray of A having only non-negative elements. If there are more than one such subarrays, return the one having earliest starting index in A.

NOTE: It is guaranteed that an answer always exists.


Problem Constraints

1 <= N <= 105

-109 <= A[i] <= 109



Input Format

The first and only argument given is the integer array A.


Output Format

Return maximum size subarray of A having only non-negative elements. If there are more than one such subarrays, return the one having earliest starting index in A.


Example Input

Input 1:

 A = [5, 6, -1, 7, 8]

Input 2:

 A = [1, 2, 3, 4, 5, 6]



Example Output

Output 1:

 [5, 6]

Output 2:

 [1, 2, 3, 4, 5, 6]
*/
vector<int> Solution::solve(vector<int> &A) {
    int f_l=-1,f_r=-1,l=0,r=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>=0) l=i;
        while(i<A.size() and A[i]>=0)
        {
            i++;
            r=i-1;
        }
        if(f_r-f_l<r-l)
        {
            f_l = l;
            f_r = r;
        }
        if(f_r-f_l==r-l and f_r<0 and f_l<0 and A[l]>0)
        {
            f_l = l;
            f_r = r;
        }
    }
    vector<int> ans;
    for(int i=f_l;i<=f_r;i++)
    {
        ans.push_back(A[i]);
    }
    return ans;
}
