class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            if (arr[low] <= arr[high])
                return low;
            int mid = low + (high - low) / 2;
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;
            if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
                return mid;
            if (arr[mid] >= arr[low])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return 0;
    }
};
