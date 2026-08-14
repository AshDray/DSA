class Solution {
public:
    int countPaths(int n, vector<vector<int>>& road) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : road) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]}); // Fix 1: Bi-directional
        }

        // Fix 3: Use long long to avoid overflow
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        vector<long long> dist(n, LONG_MAX);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        q.push({0, 0});
        int mod = 1e9 + 7;

        while (!q.empty()) {
            auto [dis, node] = q.top();
            q.pop();

            if (dis > dist[node]) continue;

            for (auto& iter : adj[node]) {
                int adjn = iter.first;
                long long edw = iter.second;

                if (dis + edw < dist[adjn]) {
                    dist[adjn] = dis + edw;
                    ways[adjn] = ways[node];
                    q.push({dist[adjn], adjn});
                } else if (dis + edw == dist[adjn]) {
                    ways[adjn] = (ways[adjn] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};