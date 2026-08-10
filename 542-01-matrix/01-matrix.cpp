class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>qp;
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(mat[i][j]==0){
            vis[i][j]=1;
            qp.push({{i,j},0});
           }
        }
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!qp.empty()){
            int row=qp.front().first.first;
            int col=qp.front().first.second;
            int steps=qp.front().second;
            qp.pop();
            dist[row][col]=steps;
            for(int i=0;i<4;i++){
                int nx=row+dx[i];
                int ny=col+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && vis[nx][ny]==0){
                    vis[nx][ny]=1;
                    qp.push({{nx,ny},steps+1});
                }
            }
        }
        return dist;
    }
};