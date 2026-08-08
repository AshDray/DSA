class Solution {
public:
int f(int i, int j, vector<int>&cuts, vector<vector<int>> &dp){
    
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int mini =INT_MIN;
    int tot;
    for(int k=i;k<=j;k++){
         tot=cuts[j+1]*cuts[k]*cuts[i-1]+f(i,k-1,cuts,dp)+f(k+1,j,cuts,dp);
        mini=max(tot,mini);
    }
    return dp[i][j]= mini;
}
    int maxCoins( vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(1);
        cuts.insert(cuts.begin(),1);
         vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        return f(1,c,cuts,dp);
    }
};