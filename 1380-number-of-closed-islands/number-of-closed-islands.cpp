class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid,int m ,int n ) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 1)
            return;
        grid[r][c]=1;
        dfs(r+1,c,grid,m,n);
        dfs(r-1,c,grid,m,n);
        dfs(r,c+1,grid,m,n);
        dfs(r,c-1,grid,m,n);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0)
                dfs(i, 0, grid, m, n);
            if (grid[i][n-1] == 0)
                dfs(i, n-1, grid, m, n);
        }
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 0)
                dfs(0, i, grid, m, n);
            if (grid[m-1][i] == 0)
                dfs(m-1, i, grid, m, n);
        }
        int ct=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    ct++;
                    dfs(i,j,grid,m,n);
                }
            }
        }
        return ct;
    }
};