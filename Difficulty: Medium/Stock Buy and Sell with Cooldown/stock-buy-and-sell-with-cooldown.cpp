#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        int buy = -arr[0], sell = 0, cool = 0;

        for (int i = 1; i < n; i++) {
            int prevBuy = buy, prevSell = sell, prevCool = cool;
            buy = max(prevBuy, prevCool - arr[i]);
            sell = prevBuy + arr[i];
            cool = max(prevCool, prevSell);
        }

        return max(sell, cool);
    }
};
