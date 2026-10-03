class Solution {
public:
    void dfs(int node, int parent, const vector<vector<pair<int, int>>>& adj,int &c) {
     
        
        for (const auto& [neighbor, cost] : adj[node]) {
            if (neighbor != parent) {
                c += cost;
                 dfs(neighbor, node, adj,c);
            }
        }
        
        return;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        // adj[u] holds pairs of {v, cost}
        // cost = 1 means original edge is u -> v (directed away from 0 during traversal)
        // cost = 0 means original edge is v -> u (already pointing toward 0)
        vector<vector<pair<int, int>>> adj(n);
        
        for (const auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v, 1}); 
            adj[v].push_back({u, 0}); 
        }
int c=0;
dfs(0, -1, adj,c);
        return c;
    }
};