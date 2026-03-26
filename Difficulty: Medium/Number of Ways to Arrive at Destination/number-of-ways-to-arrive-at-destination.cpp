class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        const long long INF = 1e18;
        const int MOD = 1e9 + 7;
        vector<pair<int,int>> adj[V];
        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> dist(V, INF);
        vector<int> ways(V, 0);

        priority_queue<
            pair<long long,int>, 
            vector<pair<long long,int>>, 
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if(time > dist[node]) continue;

            for(auto &it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                if(time + wt < dist[adjNode]) {
                    dist[adjNode] = time + wt;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if(time + wt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[V-1];
    }
};