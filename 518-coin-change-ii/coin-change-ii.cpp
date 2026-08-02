class Solution {
public:
int f( vector<int>& coins, vector<vector<int>>& dp,int a,int i){
    if(i==0){
        return ((a%coins[0])==0);
    }
    if(dp[i][a]!=-1)return dp[i][a];
    int nottaken = f(coins,dp,a,i-1);
    int taken=0;
    if(coins[i]<=a){
        taken=f(coins,dp,a-coins[i],i);
    }
    return dp[i][a]=taken+nottaken;

}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(coins,dp,amount,n-1);
    }
};