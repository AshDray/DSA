#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool isSubsequence(const string& a, const string& b) {
        int i = 0, j = 0;
        while (i < a.length() && j < b.length()) {
            if (a[i] == b[j]) {
                i++;
            }
            j++;
        }
        return i == a.length();
    }

public:
    int findLUSlength(vector<string>& strs) {
        int maxLen = -1;
        int n = strs.size();

        for (int i = 0; i < n; i++) {
            bool isUncommon = true;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                if (isSubsequence(strs[i], strs[j])) {
                    isUncommon = false;
                    break;
                }
            }

            if (isUncommon) {
                maxLen = max(maxLen, (int)strs[i].length());
            }
        }

        return maxLen;
    }
};