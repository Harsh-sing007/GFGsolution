class Solution {
public:
    long long countIncreasing(vector<int>& arr) {
        long long ans = 0;
        int count = 1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            
            ans += (count - 1);
        }

        return ans;
    }
};