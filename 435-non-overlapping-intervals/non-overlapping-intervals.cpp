class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& s) {
        sort(s.begin(),s.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        int ct=0;
        int prev=s[0][1];
        for(int i=1;i<s.size();i++){
           if(prev>s[i][0])ct++;
           else prev=s[i][1];
        }
        return ct;
    }
};