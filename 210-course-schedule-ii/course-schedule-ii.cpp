class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& ps) {
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        for(int i=0;i<ps.size();i++){
            adj[ps[i][1]].push_back(ps[i][0]);
            indeg[ps[i][0]]++;
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            cnt++;
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                    
                }
            }
        }
        if(cnt==n)return ans;
        else return {};

    }
};