class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> s;
        int y = s.size();
        int ad=0;
        int ct=0;
        s.insert(0);
        for (auto x : nums) {
            y = s.size();
            ad+=x;
            s.insert(ad % k);
            if(ct){
                if(x % k != 0)ct=0;
            }
            if (y == s.size()) {
                if (x % k == 0){ct++;
                if(ct>1)return true;

                    continue;}
                else
                    return true;
            }
        }
        return false;
    }
};