class Solution {
  public:
    int subarrayXor(vector<int> &arr, int k) {
        
        unordered_map<int,int> mp;
        int xr = 0;
        int count = 0;
        
        mp[0] = 1;   // Important case
        
        for(int i=0;i<arr.size();i++){
            
            xr ^= arr[i];
            
            if(mp.find(xr ^ k) != mp.end()){
                count += mp[xr ^ k];
            }
            
            mp[xr]++;
        }
        
        return count;
    }
};