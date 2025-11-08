#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to find the last non-conflicting job
    int findLastNonConflict(vector<vector<int>>& jobs, int i) {
        int low = 0, high = i - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (jobs[mid][1] <= jobs[i][0]) {
                if (jobs[mid + 1][1] <= jobs[i][0])
                    low = mid + 1;
                else
                    return mid;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
    int maxProfit(vector<vector<int>>& jobs) {
        int n = jobs.size();

        // Sort jobs by end time
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        vector<int> dp(n);
        dp[0] = jobs[0][2]; // profit of the first job

        for (int i = 1; i < n; i++) {
            int includeProfit = jobs[i][2];
            int l = findLastNonConflict(jobs, i);
            if (l != -1)
                includeProfit += dp[l];

            dp[i] = max(dp[i - 1], includeProfit);
        }

        return dp[n - 1];
    }
};

