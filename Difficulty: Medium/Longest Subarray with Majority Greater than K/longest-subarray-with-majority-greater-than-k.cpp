#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        
        unordered_map<int,int> firstIndex;
        int prefixSum = 0;
        int maxLen = 0;
        
        for(int i=0;i<arr.size();i++){
            
            if(arr[i] > k)
                prefixSum += 1;
            else
                prefixSum -= 1;
            if(prefixSum > 0)
                maxLen = i + 1;
            if(firstIndex.find(prefixSum) == firstIndex.end())
                firstIndex[prefixSum] = i;
            if(firstIndex.find(prefixSum-1) != firstIndex.end()){
                maxLen = max(maxLen,
                            i - firstIndex[prefixSum-1]);
            }
        }
        
        return maxLen;
    }
};