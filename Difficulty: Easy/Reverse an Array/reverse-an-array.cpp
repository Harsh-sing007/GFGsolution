class Solution {
public:
    void reverseArray(std::vector<int>& arr) {
        int start = 0, end = arr.size() - 1;
        while (start < end) {
            std::swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
};
