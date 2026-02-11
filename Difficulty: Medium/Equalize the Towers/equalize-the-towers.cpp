class Solution {
public:
    long long findCost(vector<int>& heights, vector<int>& cost, int target) {
        long long total = 0;
        for(int i = 0; i < heights.size(); i++) {
            total += 1LL * abs(heights[i] - target) * cost[i];
        }
        return total;
    }

    long long minCost(vector<int>& heights, vector<int>& cost) {
        int left = *min_element(heights.begin(), heights.end());
        int right = *max_element(heights.begin(), heights.end());

        long long ans = LLONG_MAX;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            long long cost1 = findCost(heights, cost, mid);
            long long cost2 = findCost(heights, cost, mid + 1);

            ans = min(cost1, cost2);

            if(cost1 < cost2)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return ans;
    }
};
