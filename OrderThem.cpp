int Solution::solve(vector<int> &A) {
    stack<int> st;
    vector<int> B;
    //st.push(A[0]);
    for(int i=0;i<A.size();i++)
    {
        if(st.empty()) st.push(A[i]);
        else if(A[i]<st.top())
        {
            st.push(A[i]);
        }
        else
        {
            while(!st.empty() and st.top()<A[i])
            {
                B.push_back(st.top());
                st.pop();
            }
            st.push(A[i]);
            
        }
    }
    while(!st.empty())
    {
        B.push_back(st.top());
        st.pop();
    }
    for(int i=0;i<B.size()-1;i++)
    {
        if(B[i]>B[i+1])
        {
            return false;
        }
    }
    return true;
}
