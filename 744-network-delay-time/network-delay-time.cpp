class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        queue<pair<int,int>>q;
        q.push({0,k});
        while(!q.empty()){
           auto it=q.front();
           q.pop();
           int time=it.first;
           int node=it.second;
           for(auto iter:adj[node]){
            int adjnode=iter.first;
            int edw=iter.second;
            if(time+edw<dist[adjnode]){
            dist[adjnode]=time+edw;
            q.push({time+edw,adjnode});
           }
        }
        
    }
    sort(dist.begin(),dist.end());
        if(dist[n-1]==INT_MAX)return -1;
        else return dist[n-1];
}};