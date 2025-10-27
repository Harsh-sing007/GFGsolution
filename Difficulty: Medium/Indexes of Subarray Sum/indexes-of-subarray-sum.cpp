class Solution {
public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int start = 0;
        long long curr_sum = 0;

        for (int end = 0; end < n; end++) {
            curr_sum += arr[end];

            // Shrink the window if sum exceeds target
            while (curr_sum > target && start < end) {
                curr_sum -= arr[start];
                start++;
            }

            // Found the subarray
            if (curr_sum == target) {
                return {start + 1, end + 1}; // 1-based indexing
            }
        }

        // No subarray found
        return {-1};
    }
};
