class Solution {
public:
int f(int i,int j, vector<vector<int>>&dp,string &s,string &t){
    if(j==t.size())return 1;
    if(i==s.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){int take=f(i+1,j+1,dp,s,t);
    int nottake=f(i+1,j,dp,s,t);
    return dp[i][j]=take+nottake;}
    else return dp[i][j]=f(i+1,j,dp,s,t);

}
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(0,0,dp,s,t);

    }
};