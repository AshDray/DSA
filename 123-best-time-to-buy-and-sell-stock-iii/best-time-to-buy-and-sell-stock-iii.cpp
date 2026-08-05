class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> ahead(2, vector<int>(3, 0));
    vector<vector<int>> cur(2, vector<int>(3, 0));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                if(buy==0){
                    cur[buy][cap]=max(ahead[0][cap],-prices[i]+ahead[1][cap]);
                }
                if(buy==1){
                    cur[buy][cap]=max(ahead[1][cap],prices[i]+ahead[0][cap-1]);
                }
            }
        }
        ahead=cur;
    } 
    return ahead[0][2];
    }
};