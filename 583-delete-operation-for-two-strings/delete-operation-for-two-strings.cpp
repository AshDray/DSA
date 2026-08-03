class Solution {
public:
    int f(string &s1,string &s2,vector<vector<int>>&dp,int i,int j){
        if(i==0 || j==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans;
        if(s1[i-1]==s2[j-1])ans=1+f(s1,s2,dp,i-1,j-1);
        else ans=max(f(s1,s2,dp,i-1,j),f(s1,s2,dp,i,j-1));
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
       int m=word1.size();
       int n=word2.size();
       vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
       int lcs=f(word1,word2,dp,m,n) ;
       int ans=m+n-2*lcs;
       return ans;
    }
};