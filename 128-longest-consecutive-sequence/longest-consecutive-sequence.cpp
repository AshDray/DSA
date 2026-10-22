class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ct=1;
        int n=nums.size();
        if(!n)return 0;
        int maxi=ct;
        for(int i=0;i<n-1;i++)
{
    if(nums[i]+1==nums[i+1]){
        ct++;
    }
    else if(nums[i]==nums[i+1])continue;
    else ct=1;
    maxi=max(maxi,ct);
    
}   
return maxi; 
}
};