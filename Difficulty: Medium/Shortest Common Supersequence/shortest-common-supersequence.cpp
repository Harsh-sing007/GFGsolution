#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSuperSeq(string X, string Y) {
        int n = X.size();
        int m = Y.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Compute LCS
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (X[i - 1] == Y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int lcsLen = dp[n][m];
        return n + m - lcsLen; // length of shortest common supersequence
    }
};
