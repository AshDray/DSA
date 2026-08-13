class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         queue<pair<int,pair<int,int>>>q;
         int m=grid[0].size();
         int n=grid.size();
         vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
         dist[0][0]=0;
         q.push({1,{0,0}});
         int dr[] = {-1, 0, 1, 0,1,1,-1,-1};
        int dc[] = {0, 1, 0, -1, 1,-1,-1,1};
        if(grid[0][0]==1)return -1;
        if(n==1 && m==1 && grid[0][0]==0)return 1;
         while(!q.empty()){
            int dis=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            for (int i = 0; i < 8; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];
                if(newr>=0 && newc>=0 && newr<n && newc <m && grid[newr][newc]==0 && dis+1<dist[newr][newc]){
                    dist[newr][newc]=dis+1;
                    q.push({dis+1,{newr,newc}});
                    if(newr==n-1 && newc==m-1)return dist[newr][newc];
                }
            }
            

         }
         return -1;

    }
};