class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int r = accumulate(arr.begin(), arr.end(), 0);
        int l = 0;
        for(int x : arr)
        {
            l = l + x;
            r = r - x;
            if(l == r)
            return true;
        }
        return false;
    }
};