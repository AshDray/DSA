class Solution {
public:
int f( vector<vector<int>>&dp,string &s,int i,int j){
    if(i>j)return 0;
    if(i==j)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans;
    if(s[i]==s[j])ans=2+f(dp,s,i+1,j-1);
    else ans=max(f(dp,s,i+1,j),f(dp,s,i,j-1));
    return dp[i][j]=ans;

}
    int minInsertions(string s) {
       int n=s.size();
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return n-f(dp,s,0,n-1);
    }
};
    