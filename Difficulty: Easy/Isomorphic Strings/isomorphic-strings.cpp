class Solution {
  public:
    bool areIsomorphic(string s1, string s2) {
        
        int map1[26] = {0};
        int map2[26] = {0};
        
        for(int i = 0; i < s1.length(); i++) {
            
            int c1 = s1[i] - 'a';
            int c2 = s2[i] - 'a';
            
            // If already mapped, check consistency
            if(map1[c1] != 0 || map2[c2] != 0) {
                if(map1[c1] != s2[i] || map2[c2] != s1[i])
                    return false;
            }
            else {
                map1[c1] = s2[i];
                map2[c2] = s1[i];
            }
        }
        
        return true;
    }
};