class Solution {
public:
bool f(int i,int target,vector<int>&a,vector<vector<int>>&dp){
    if(target==0)return true;
    if(i==0)return target==a[0];
    if(dp[i][target]!=-1)return dp[i][target];
    bool take=false;
    if(a[i]<=target)take=f(i-1,target-a[i],a,dp); 
    bool nottake=f(i-1,target,a,dp); 
    return dp[i][target]=take||nottake;
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int k=sum/2;
        if (sum%2)return false;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return f(n-1,k,nums,dp);
    }
};