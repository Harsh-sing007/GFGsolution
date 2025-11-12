#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wildCard(string text, string pat) {
        int n = pat.size(), m = text.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        // '*' at the beginning of pattern can match empty text
        for (int i = 1; i <= n; i++) {
            if (pat[i - 1] == '*')
                dp[i][0] = dp[i - 1][0];
            else
                break;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pat[i - 1] == text[j - 1] || pat[i - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (pat[i - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};
