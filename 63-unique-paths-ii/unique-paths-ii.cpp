class Solution {
public:
int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& a){
        
        if(i<0 || j<0||a[i][j]==1){
            return 0;
        }
        if(i==0 && j==0){
            return 1;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int up=f(i,j-1,dp,a);
        int down=f(i-1,j,dp,a);
        return dp[i][j]=up+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp,obstacleGrid);
    }
};
