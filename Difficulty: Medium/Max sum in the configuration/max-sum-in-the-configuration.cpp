class Solution {
public:
    int maxSum(vector<int>& a) {
        int n = a.size();
        int arrSum = 0;
        int currVal = 0;

        for (int i = 0; i < n; i++) {
            arrSum += a[i];
            currVal += i * a[i];
        }

        int res = currVal;

        for (int i = 1; i < n; i++) {
            currVal = currVal + arrSum - n * a[n - i];
            res = max(res, currVal);
        }

        return res;
    }
};
