class Solution {
public:
    int equalSumSpan(vector<int>& a1, vector<int>& a2) {
        
        unordered_map<int,int> mp;
        int diff = 0, maxLen = 0;

        for(int i = 0; i < a1.size(); i++) {
            
            diff += a1[i] - a2[i];

            // If diff = 0 → span from 0 to i
            if(diff == 0)
                maxLen = i + 1;

            // If diff seen before
            else if(mp.count(diff))
                maxLen = max(maxLen, i - mp[diff]);
            else
                mp[diff] = i;
        }

        return maxLen;
    }
};