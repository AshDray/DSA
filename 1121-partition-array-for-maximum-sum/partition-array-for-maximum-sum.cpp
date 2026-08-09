class Solution {
public:
int f(vector<int>&dp,int start, int k , vector<int> &g){
    int n=g.size();
    if(start==n)return 0;
    if(dp[start]!=-1)return dp[start];
    int maxi=0;
    int tot=0;
    for(int lt=1;lt<=k && lt+start<=n;lt++){
      maxi=max(maxi,g[lt+start-1]);
        int sm=maxi*lt+f(dp,start+lt,k,g);
         tot=max(tot,sm);
    }
    return dp[start]=tot;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return f(dp,0,k,arr);
    }
};