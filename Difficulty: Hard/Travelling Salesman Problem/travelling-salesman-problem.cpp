class Solution {
public:
    int solve(vector<vector<int>>& cost, int n,
              int mask, int pos, vector<vector<int>>& dp) {

        if (mask == (1 << n) - 1)
            return cost[pos][0];

        if (dp[mask][pos] != -1)
            return dp[mask][pos];

        int ans = INT_MAX;

        for (int city = 0; city < n; city++) {
            if (!(mask & (1 << city))) {
                int newMask = mask | (1 << city);
                int newCost = cost[pos][city] 
                           + solve(cost, n, newMask, city, dp);
                ans = min(ans, newCost);
            }
        }

        return dp[mask][pos] = ans;
    }
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        vector<vector<int>> dp(1 << n, vector<int>(n, -1));

        int startMask = 1; // city 0 visited
        return solve(cost, n, startMask, 0, dp);
    }
};
