class Solution {
public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> intervals;

        // Step 1: Build intervals
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                int l = max(0, i - arr[i]);
                int r = min(n - 1, i + arr[i]);
                intervals.push_back({l, r});
            }
        }

        if (intervals.empty())
            return -1;

        // Step 2: Sort by start time
        sort(intervals.begin(), intervals.end());

        int coveredTill = -1;   // last covered hour
        int i = 0, ans = 0;
        int m = intervals.size();

        // Step 3: Greedy covering
        while (coveredTill < n - 1) {
            int bestReach = coveredTill;

            // Find all intervals that can extend coverage
            while (i < m && intervals[i].first <= coveredTill + 1) {
                bestReach = max(bestReach, intervals[i].second);
                i++;
            }

            // No progress → gap exists
            if (bestReach == coveredTill)
                return -1;

            ans++;
            coveredTill = bestReach;
        }

        return ans;
    }
};
