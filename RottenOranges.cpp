int Solution::solve(vector<vector<int> > &A) {
    int ans = 0;
    pair<int,int> p;
    int rows = A.size();
    int cols = A[0].size();
    queue<pair<int,int> > q;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(A[i][j]==2)
            {
                p.first = i;
                p.second = j;
                q.push(p);
            }
        }
    }
    while(!q.empty())
    {
        int n = q.size();
        for(int i=0;i<n;i++)
        {
            pair<int,int> pq = q.front();
            q.pop();
            if(pq.first-1>=0 and pq.second>=0 and pq.first-1<rows and pq.second<cols and A[pq.first-1][pq.second]==1)
            {
                A[pq.first-1][pq.second]=2;
                p.first = pq.first-1;
                p.second = pq.second;
                q.push(p);
            }
            if(pq.first+1>=0 and pq.second>=0 and pq.first+1<rows and pq.second<cols and A[pq.first+1][pq.second]==1)
            {
                A[pq.first+1][pq.second]=2;
                p.first = pq.first+1;
                p.second = pq.second;
                q.push(p);
            }
            if(pq.first>=0 and pq.second-1>=0 and pq.first<rows and pq.second-1<cols and A[pq.first][pq.second-1]==1)
            {
                A[pq.first][pq.second-1]=2;
                p.first = pq.first;
                p.second = pq.second-1;
                q.push(p);
            }
            if(pq.first>=0 and pq.second+1>=0 and pq.first<rows and pq.second+1<cols and A[pq.first][pq.second+1]==1)
            {
                A[pq.first][pq.second+1]=2;
                p.first = pq.first;
                p.second = pq.second+1;
                q.push(p);
            }
        }
        ans++;
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(A[i][j]==1) return -1;
        }
    }
    return ans-1;
}
