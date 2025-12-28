class Solution {
public:
    bool canMake(vector<int>& rank, int orders, long long T) {
        long long total = 0;

        for (int r : rank) {
            long long x = (2 * T) / r;
            long long k = (long long)((sqrt(1 + 4 * x) - 1) / 2);

            total += k;
            if (total >= orders) return true;
        }
        return false;
    }

    long long minTime(vector<int>& rank, int orders) {
        long long low = 0;
        long long high = 1e18;
        long long ans = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canMake(rank, orders, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
