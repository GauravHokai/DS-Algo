int Solution::solve(vector<int> &A) {
    int ans = 0;
    priority_queue<int, vector<int>,greater<int>> p;
    for(int i:A)
    {
        p.push(i);
    }
    while(p.size()>1)
    {
        int a = p.top();
        p.pop();
        int b = p.top();
        p.pop();
        ans += a+b;
        p.push(a+b);
        
    }
    return ans;
}
