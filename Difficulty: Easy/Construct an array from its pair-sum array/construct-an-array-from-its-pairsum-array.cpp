class Solution {
public:
    vector<int> constructArr(vector<int> &arr) {
        int m = arr.size();
        
        int n = 0;
        for (int i = 2; i <= 2000; i++) {
            if (i * (i - 1) / 2 == m) {
                n = i;
                break;
            }
        }

        vector<int> res;
        if (n == 0) return res;   

        if (m == 1) {
            res.push_back(0);
            res.push_back(arr[0]);
            return res;
        }

        int a = (arr[0] + arr[1] - arr[n - 1]) / 2;
        res.push_back(a);

        for (int i = 1; i < n; i++) {
            res.push_back(arr[i - 1] - a);
        }

        return res;
    }
};
