#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        // Count frequencies of each task
        std::vector<int> freq(26, 0);
        int maxFreq = 0;
        for (char task : tasks) {
            freq[task - 'A']++;
            maxFreq = std::max(maxFreq, freq[task - 'A']);
        }

        // Count how many tasks share the maximum frequency
        int maxFreqCount = 0;
        for (int count : freq) {
            if (count == maxFreq) {
                maxFreqCount++;
            }
        }

        // Calculate minimum intervals based on frame structure
        int time = (maxFreq - 1) * (n + 1) + maxFreqCount;

        // If task count is larger, no idle slots are required
        return std::max((int)tasks.size(), time);
    }
};