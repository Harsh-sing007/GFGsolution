class Solution {
public:
    int maxOnes(vector<int>& arr, int k) {
        int l = 0, zeros = 0, ans = 0;

        for (int r = 0; r < arr.size(); r++) {
            if (arr[r] == 0) zeros++;

            while (zeros > k) {
                if (arr[l] == 0) zeros--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
