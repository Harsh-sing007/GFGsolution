class Solution {
public:
    int timer;

    void dfs(int node, int parent, vector<int> adj[], vector<int>& vis,
             vector<int>& tin, vector<int>& low, vector<int>& mark) {

        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;

        for (auto it : adj[node]) {

            if (it == parent) continue;

            if (!vis[it]) {
                dfs(it, node, adj, vis, tin, low, mark);

                low[node] = min(low[node], low[it]);

                // ARTICULATION POINT CONDITION
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }

                child++;
            }
            else {
                // BACK EDGE
                low[node] = min(low[node], tin[it]);
            }
        }

        // ROOT NODE CASE
        if (parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {

        vector<int> adj[V];

        // Build graph
        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(V, 0), tin(V), low(V), mark(V, 0);
        timer = 0;

        // For disconnected graph
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, vis, tin, low, mark);
            }
        }

        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (mark[i]) ans.push_back(i);
        }

        if (ans.size() == 0) return {-1};

        sort(ans.begin(), ans.end());
        return ans;
    }
};