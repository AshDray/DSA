class Solution {
public:
void dfs(int node,vector<int> al[],vector<int> &vis){
    vis[node]=1;
    for(auto j:al[node]){
        if(!vis[j])dfs(j,al,vis);
    }
}
    int findCircleNum(vector<vector<int>>& c) {
        int v = c.size();
        vector<int> al[v];
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (c[i][j] == 1 && i != j) {
                    al[i].push_back(j);
                
                }
            }
        }
        vector<int> vis(v,0);
        int count=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                count++;
                dfs(i,al,vis);
            }
        }
        return count;
    }
};