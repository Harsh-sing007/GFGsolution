class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        int currXor = 0;

        // First window
        for (int i = 0; i < k; i++) {
            currXor ^= arr[i];
        }

        int maxXor = currXor;

        // Sliding window
        for (int i = k; i < n; i++) {
            currXor ^= arr[i - k]; // remove outgoing
            currXor ^= arr[i];     // add incoming
            maxXor = max(maxXor, currXor);
        }

        return maxXor;
    }
};
