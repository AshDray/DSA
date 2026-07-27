class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days.back();
        vector<int> dp(lastDay + 1, 0);
        unordered_set<int> travelDays(days.begin(), days.end());

        for (int i = 1; i <= lastDay; i++) {
            if (travelDays.find(i) == travelDays.end()) {
                dp[i] = dp[i - 1];
            } else {
                int day1 = dp[i - 1] + costs[0];
                int day7 = dp[max(0, i - 7)] + costs[1];
                int day30 = dp[max(0, i - 30)] + costs[2];
                dp[i] = min({day1, day7, day30});
            }
        }

        return dp[lastDay];
    }
};