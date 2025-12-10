class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        long long actual_sum = 0;
        long long actual_sum_sq = 0;
        
        for (int num : arr) {
            actual_sum += num;
            actual_sum_sq += (long long)num * num;
        }
        
        long long expected_sum = (long long)n * (n + 1) / 2;
        long long expected_sum_sq = (long long)n * (n + 1) * (2 * n + 1) / 6;
        
        // x - y (where x is repeating, y is missing)
        long long diff = actual_sum - expected_sum;
        
        // x^2 - y^2 = (x + y)(x - y)
        long long sum_xy = (actual_sum_sq - expected_sum_sq) / diff;
        
        // Solving: x - y = diff and x + y = sum_xy
        int repeating = (diff + sum_xy) / 2;
        int missing = sum_xy - repeating;
        
        return {repeating, missing};
    }
};