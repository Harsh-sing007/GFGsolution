class Solution {
public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();
        
        unordered_set<int> s;
        
        for(int x : arr)
            s.insert(x * x);
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int sum = arr[i]*arr[i] + arr[j]*arr[j];
                
                if(s.count(sum))
                    return true;
            }
        }
        
        return false;
    }
};