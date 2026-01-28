class Solution {
  public:
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size();
        int mid = n / 2;

        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());

        vector<long long> sumL, sumR;

        // generate subset sums of left half
        int nL = left.size();
        for (int mask = 0; mask < (1 << nL); mask++) {
            long long s = 0;
            for (int i = 0; i < nL; i++) {
                if (mask & (1 << i))
                    s += left[i];
            }
            sumL.push_back(s);
        }
        int nR = right.size();
        for (int mask = 0; mask < (1 << nR); mask++) {
            long long s = 0;
            for (int i = 0; i < nR; i++) {
                if (mask & (1 << i))
                    s += right[i];
            }
            sumR.push_back(s);
        }

        sort(sumR.begin(), sumR.end());

        int ans = 0;
        for (long long s : sumL) {
            long long need = k - s;
            ans += upper_bound(sumR.begin(), sumR.end(), need) -
                   lower_bound(sumR.begin(), sumR.end(), need);
        }

        return ans;
    }
};

