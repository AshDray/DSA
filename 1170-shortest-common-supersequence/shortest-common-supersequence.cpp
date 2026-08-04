class Solution {
public:
int lcs(int i,int j,vector<vector<int>>&dp,string &s, string&t){
    if(i==0 || j==0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i-1]==t[j-1])return dp[i][j]=1+lcs(i-1,j-1,dp,s,t);
    else return dp[i][j]=max(lcs(i-1,j,dp,s,t),lcs(i,j-1,dp,s,t));
}
   string shortestCommonSupersequence(string s, string t){
       int n=s.size(); 
       int m=t.size(); 
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       lcs(n,m,dp,s,t);
       int i = n, j = m;
        string result = "";

        while (i > 0 && j > 0) {
            if (s[i - 1] == t[j - 1]) {
                result.push_back(s[i - 1]);
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                result.push_back(s[i - 1]);
                i--;
            } else {
                result.push_back(t[j - 1]);
                j--;
            }
        }
        while (i > 0) {
            result.push_back(s[i - 1]);
            i--;
        }
        while (j > 0) {
            result.push_back(t[j - 1]);
            j--;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};