class Solution {
public:
    int maxProfit(vector<int>& ps) {
        int maxi=0;
        int mini=INT_MAX;
        for(int p : ps){
            if(p<mini)mini=p;
            maxi=max(maxi,p-mini);
        }
        
        return maxi;
    }
};