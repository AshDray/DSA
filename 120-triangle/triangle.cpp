class Solution {
public:
int f(int i,int j,int n,vector<vector<int>>& a,vector<vector<int>>& dp){
     if(dp[i][j]!=-100000)return dp[i][j];
     if(i==n-1)return dp[i][j]=a[i][j];
     int down=a[i][j]+f(i+1,j,n,a,dp);
     int btmrt=a[i][j]+f(i+1,j+1,n,a,dp);
     return dp[i][j]=min(down,btmrt);
}
    int minimumTotal(vector<vector<int>>& triangle) {
      int n=triangle.size();
      vector<vector<int>>dp(n,vector<int>(n,-100000));
      return f(0,0,n,triangle,dp);  
    }
};