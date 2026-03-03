class Solution {
public:
    int maxSubarrayXOR(vector<int> &arr, int k) {
        int n = arr.size();
        int currentXor = 0;
        for (int i = 0; i < k; i++) {
            currentXor ^= arr[i];
        }

        int maxXor = currentXor;
        for (int i = k; i < n; i++) {
            currentXor ^= arr[i - k]; 
            currentXor ^= arr[i];    
            maxXor = max(maxXor, currentXor);
        }

        return maxXor;
    }
};