#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string p) {
        
        vector<int> freq(256,0);
        
        for(char c : p){
            freq[c]++;
        }
        
        int left = 0;
        int count = p.size();
        
        int start = 0;
        int minLen = INT_MAX;
        
        for(int right = 0; right < s.size(); right++){
            
            if(freq[s[right]] > 0)
                count--;
            
            freq[s[right]]--;
            
            while(count == 0){
                
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }
                
                freq[s[left]]++;
                
                if(freq[s[left]] > 0)
                    count++;
                
                left++;
            }
        }
        
        if(minLen == INT_MAX)
            return "";
            
        return s.substr(start, minLen);
    }
};