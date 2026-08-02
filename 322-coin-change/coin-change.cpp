class Solution {
public:
int f(vector<int>&dp,vector<int>coins,int rem){
    if(rem<0)return -1;
    if(rem==0)return 0;
    if(dp[rem]!=-2)return dp[rem];
    int mini=INT_MAX;
    for(int coin:coins){
       int res=f(dp,coins,rem-coin);
       if(res>=0 && res<mini){
        mini=1+res;
       }
       
    }
    dp[rem]=(mini==INT_MAX)?-1:mini;
       return dp[rem];
    
}
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int>dp(amount+1,-2);
        return f(dp,coins,amount);
    }
};