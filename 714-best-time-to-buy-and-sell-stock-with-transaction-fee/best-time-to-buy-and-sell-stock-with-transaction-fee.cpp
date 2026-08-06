class Solution {
public:
    int maxProfit(vector<int>& ps, int fee) {
        if(ps.size()==0)return 0;
        vector<int>ahead(2,0);
        vector<int>cur(2,0);
        int n =ps.size();
        int pft;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                if(buy==0){
                     pft=max(ahead[0],-ps[i]+ahead[1]);
                }
            else pft=max(ahead[1],ps[i]-fee+ahead[0]);
            cur[buy]=pft;
            }
            ahead=cur;
        }
        return cur[0];
    }
};