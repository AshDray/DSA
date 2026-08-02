class Solution {
public:
int f(vector<vector<int>>&dp,vector<int>&nums,int tt,int i){
    if(i==0){
        if(tt==0 && nums[0]==0)return 2;
        if(tt==0 || tt==nums[0])return 1;
        return 0;
    }
    if(dp[i][tt]!=-1)return dp[i][tt];
    int notpick=f(dp,nums,tt,i-1);
    int pick=0;
    if(nums[i]<=tt){
        pick=f(dp,nums,tt-nums[i],i-1);
    }
    return dp[i][tt]=pick+notpick;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int totsm=accumulate(nums.begin(),nums.end(),0);
        if(totsm-target<0 || ((totsm-target)%2))return 0;
        int tt=(totsm-target)/2;
        vector<vector<int>>dp(nums.size(),vector<int>(tt+1,-1));
        return f(dp,nums,tt,nums.size()-1);

    }
};