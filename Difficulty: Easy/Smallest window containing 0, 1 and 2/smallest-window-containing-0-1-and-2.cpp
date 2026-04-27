class Solution {
public:
    int smallestSubstring(string s) {
        int n = s.size();
        vector<int> count(3, 0);
        
        int left = 0, ans = INT_MAX;
        
        for (int right = 0; right < n; right++) {
            count[s[right] - '0']++;
            
            // Check if all 3 are present
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                ans = min(ans, right - left + 1);
                
                // shrink window
                count[s[left] - '0']--;
                left++;
            }
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};