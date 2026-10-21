class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        sort(v.begin(),v.end());
        int ct=0;
        int p=v[0];
        int l=v.size();
        vector<int>ans;
        for(auto n:v){
            if(p==n)ct++;
            else{
                if(ct>(l/3))ans.push_back(p) ;
                ct=1;     
                p=n;     
                 }

        }
 if(ct>(l/3))ans.push_back(p) ;        return ans;
    }
};