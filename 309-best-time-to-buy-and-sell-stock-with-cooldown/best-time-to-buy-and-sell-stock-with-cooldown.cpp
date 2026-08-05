class Solution {
public:
int f(vector<vector<int>>&dp,vector<int>&ps,int n,int i,int buy){
    if(i>=n)return 0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    int pft;
    if(buy==0){
        pft=max(f(dp,ps,n,i+1,0),-ps[i]+f(dp,ps,n,i+1,1));
    }
    else pft=max(f(dp,ps,n,i+1,1),ps[i]+f(dp,ps,n,i+2,0));
    return dp[i][buy]=pft;
}
    int maxProfit(vector<int>& ps) {
        int n=ps.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(dp,ps,n,0,0);
    }
};