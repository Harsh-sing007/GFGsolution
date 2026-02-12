class Solution {
public:
    bool canAchieve(vector<long long>& arr, int n, int k, int w, long long target) {
        vector<long long> diff(n + 1, 0);
        long long operations = 0;
        long long currentAdd = 0;

        for (int i = 0; i < n; i++) {
            currentAdd += diff[i];
            long long currentHeight = arr[i] + currentAdd;

            if (currentHeight < target) {
                long long need = target - currentHeight;
                operations += need;
                if (operations > k) return false;

                currentAdd += need;
                if (i + w < n)
                    diff[i + w] -= need;
            }
        }
        return true;
    }

    int maxMinHeight(vector<int>& arr, int k, int w) {
        int n = arr.size();
        long long low = *min_element(arr.begin(), arr.end());
        long long high = low + k;
        long long ans = low;

        vector<long long> temp(arr.begin(), arr.end());

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canAchieve(temp, n, k, w, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
