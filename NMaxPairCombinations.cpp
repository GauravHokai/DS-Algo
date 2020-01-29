vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    priority_queue<pair<int, pair<int,int> > > pq;
    set<pair<int,int>>s;
    vector<int> result;
    int n = A.size();
    pq.push({A[0]+B[0],{0,0}});
    s.insert({0,0});
    while(!pq.empty())
    {
        pair<int, pair<int,int> > temp = pq.top();
        pq.pop();
        result.push_back(temp.first);
        int i = temp.second.first;
        int j = temp.second.second;
        if(i+1<n and s.find({i+1,j})==s.end())
        {
            pq.push({A[i+1]+B[j],{i+1,j}});
            s.insert({i+1,j});
        }
        if(j+1<n and s.find({i,j+1})==s.end())
        {
            pq.push({A[i]+B[j+1],{i,j+1}});
            s.insert({i,j+1});
        }
        if(result.size()==n)
        {
            break;
        }
        
    }
    return result;
}
