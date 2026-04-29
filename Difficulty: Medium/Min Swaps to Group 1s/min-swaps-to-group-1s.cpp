class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Count total 1s
        int ones = 0;
        for (int x : arr) {
            if (x == 1) ones++;
        }
        
        // Step 2: If no 1s
        if (ones == 0) return -1;
        
        // Step 3: Count zeros in first window
        int zeroCount = 0;
        for (int i = 0; i < ones; i++) {
            if (arr[i] == 0) zeroCount++;
        }
        
        int minSwaps = zeroCount;
        
        // Step 4: Sliding window
        for (int i = ones; i < n; i++) {
            // Remove left element
            if (arr[i - ones] == 0) zeroCount--;
            
            // Add new element
            if (arr[i] == 0) zeroCount++;
            
            minSwaps = min(minSwaps, zeroCount);
        }
        
        return minSwaps;
    }
};