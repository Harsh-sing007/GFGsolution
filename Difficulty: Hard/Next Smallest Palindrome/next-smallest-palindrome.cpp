class Solution {
public:
    vector<int> nextPalindrome(vector<int> &num) {
        int n = num.size();
        vector<int> res = num;
        int i = 0, j = n - 1;
        while (i < j) {
            res[j] = res[i];
            i++; j--;
        }
        bool greater = false;
        for (int k = 0; k < n; k++) {
            if (res[k] > num[k]) {
                greater = true;
                break;
            }
            else if (res[k] < num[k]) break;
        }

        if (greater) return res;
        int carry = 1;
        int mid = (n - 1) / 2;
        i = mid;
        j = (n % 2 == 0) ? mid + 1 : mid;

        while (i >= 0) {
            int sum = res[i] + carry;
            carry = sum / 10;
            res[i] = sum % 10;
            res[j] = res[i];
            i--;
            j++;
        }
        if (carry) {
            vector<int> ans(n + 1, 0);
            ans[0] = 1;
            ans[n] = 1;
            return ans;
        }

        return res;
    }
};