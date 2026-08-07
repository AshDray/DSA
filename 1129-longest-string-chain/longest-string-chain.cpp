class Solution {
public:
    static bool cmp(string& s, string& t) { return (s.size() < t.size()); }
    int cp(string &s, string &t){
        if(s.size()!=t.size()+1)return false;
        int i=0,j=0;
        while(i<s.size()){
            if(j<t.size()&&s[i]==t[j]){i++;j++;}
            else i++;
        }
        if(i==s.size()&&j==t.size())return true;
        else return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), cmp);
        vector<int> v(n, 1);
        int maxlen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (cp(words[i], words[j]) && v[i] < v[j] + 1) {
                    v[i] = v[j] + 1;
                }
            }
            if (v[i] > maxlen)
                maxlen = v[i];
        }
        return maxlen;
    }
};