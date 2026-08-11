class Solution {
public:
bool dfs(vector<int>&vis,vector<vector<int>>&adj,int node,int col){
    vis[node]=col;
    for(auto it:adj[node]){
        if(vis[it]==-1){if(dfs(vis,adj,it,!col)==false)return false;}
        else if(vis[it]==vis[node])return false;

    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(dfs(color,graph,i,0)==false)return false;
            }
        }
        return true;
    }
};