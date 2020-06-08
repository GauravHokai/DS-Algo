vector<vector<int> > Solution::solve(vector<vector<int> > &A) {
    int rows = A.size(), cols = A[0].size();
    vector<vector<int> > B(rows, vector<int>(cols,0));
    queue<pair<int,int>> q;
    pair<int,int> p;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(A[i][j]==1)
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
        while(n--)
        {
            pair<int,int> pq = q.front();
            q.pop();
            if(pq.first-1>=0 and pq.second>=0 and pq.first-1<rows and pq.second<cols and A[pq.first-1][pq.second]==0 and B[pq.first-1][pq.second]==0)
            {
                B[pq.first-1][pq.second] = B[pq.first][pq.second]+1;
                p.first = pq.first-1;
                p.second = pq.second;
                q.push(p);
            }
            if(pq.first+1>=0 and pq.second>=0 and pq.first+1<rows and pq.second<cols and A[pq.first+1][pq.second]==0 and B[pq.first+1][pq.second]==0)
            {
                B[pq.first+1][pq.second] = B[pq.first][pq.second]+1;
                p.first = pq.first+1;
                p.second = pq.second;
                q.push(p);
            }
            if(pq.first>=0 and pq.second-1>=0 and pq.first<rows and pq.second-1<cols and A[pq.first][pq.second-1]==0 and B[pq.first][pq.second-1]==0)
            {
                B[pq.first][pq.second-1] = B[pq.first][pq.second]+1;
                p.first = pq.first;
                p.second = pq.second-1;
                q.push(p);
            }
            if(pq.first>=0 and pq.second+1>=0 and pq.first<rows and pq.second+1<cols and A[pq.first][pq.second+1]==0 and B[pq.first][pq.second+1]==0)
            {
                B[pq.first][pq.second+1] = B[pq.first][pq.second]+1;
                p.first = pq.first;
                p.second = pq.second+1;
                q.push(p);
            }
        }
    }
    return B;
}
