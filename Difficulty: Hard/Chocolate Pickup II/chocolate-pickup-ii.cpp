#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& mat, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2; // derived
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
            mat[r1][c1] == -1 || mat[r2][c2] == -1)
            return -1e9; // invalid path

        if (r1 == n - 1 && c1 == n - 1) return mat[r1][c1];

        if (dp[r1][c1][r2] != -1) return dp[r1][c1][r2];

        int res = 0;
        if (r1 == r2 && c1 == c2)
            res += mat[r1][c1];
        else
            res += mat[r1][c1] + mat[r2][c2];

        int temp = max({
            solve(mat, r1 + 1, c1, r2 + 1), // down, down
            solve(mat, r1, c1 + 1, r2),     // right, right
            solve(mat, r1 + 1, c1, r2),     // down, right
            solve(mat, r1, c1 + 1, r2 + 1)  // right, down
        });

        res += temp;
        return dp[r1][c1][r2] = res;
    }

    int chocolatePickup(vector<vector<int>>& mat) {
        n = mat.size();
        dp.assign(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int ans = solve(mat, 0, 0, 0);
        return max(0, ans);
    }
};
