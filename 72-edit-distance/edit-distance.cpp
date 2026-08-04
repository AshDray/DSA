class Solution {
private:
    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {
        if (i == 0) return j;
        if (j == 0) return i;

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i - 1] == word2[j - 1]) {
            return dp[i][j] = solve(i - 1, j - 1, word1, word2, dp);
        }

       
        int insertOp  = 1 + solve(i, j - 1, word1, word2, dp);
        int deleteOp  = 1 + solve(i - 1, j, word1, word2, dp);
        int replaceOp = 1 + solve(i - 1, j - 1, word1, word2, dp);

        return dp[i][j] = min({insertOp, deleteOp, replaceOp});
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(n, m, word1, word2, dp);
    }
};