#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;

    int solve(int i, int j, int k, vector<vector<int>>& mat, vector<vector<vector<int>>>& dp) {
        // Out of bounds
        if (i >= n || j >= m)
            return 0;

        // Memoized result
        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        // If at bottom-right
        if (i == n - 1 && j == m - 1)
            return (k == mat[i][j]) ? 1 : 0;

        int remaining = k - mat[i][j];
        if (remaining < 0)
            return 0;

        int down = solve(i + 1, j, remaining, mat, dp);
        int right = solve(i, j + 1, remaining, mat, dp);

        return dp[i][j][k] = down + right;
    }

    int numberOfPath(vector<vector<int>>& mat, int k) {
        n = mat.size();
        m = mat[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        return solve(0, 0, k, mat, dp);
    }
};
