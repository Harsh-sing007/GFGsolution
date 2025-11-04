#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int left = 0, right = arr.size() - 1;
        vector<vector<int>> result;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == 0) {
                result.push_back({arr[left], arr[right]});
                int leftVal = arr[left], rightVal = arr[right];
                while (left < right && arr[left] == leftVal) left++;
                while (left < right && arr[right] == rightVal) right--;
            } 
            else if (sum < 0) left++;
            else right--;
        }
        sort(result.begin(), result.end());
        return result;
    }
};
