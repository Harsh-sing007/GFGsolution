class Solution {
public:
    int searchInsertK(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        int ans = arr.size();  // default insert at end

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == k) {
                return mid;
            }
            else if (arr[mid] > k) {
                ans = mid;      // possible insert position
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
