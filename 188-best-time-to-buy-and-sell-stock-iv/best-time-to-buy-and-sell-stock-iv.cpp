class Solution {
public:
int f(vector<vector<vector<int>>>&dp,vector<int>&ps,int n,int i,int buy,int cap){
    if(i==n || cap==0)return 0;
    if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
    int pft;
    if(buy==0){
        pft=max(f(dp,ps,n,i+1,0,cap),-ps[i]+f(dp,ps,n,i+1,1,cap));
    }
    else pft=max(f(dp,ps,n,i+1,1,cap),ps[i]+f(dp,ps,n,i+1,0,cap-1));
    return dp[i][buy][cap]=pft;
}
    int maxProfit(int k, vector<int>& ps) {
        int n=ps.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(dp,ps,n,0,0,k);
    }
};