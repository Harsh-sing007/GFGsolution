class Solution {
  public:
    vector<string> ans;
    
    void solve(string &s, vector<bool> &visited, string &curr) {
        if (curr.size() == s.size()) {
            ans.push_back(curr);
            return;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (visited[i])
                continue;
            if (i > 0 && s[i] == s[i - 1] && !visited[i - 1])
                continue;
                
            visited[i] = true;
            curr.push_back(s[i]);
            
            solve(s, visited, curr);
            
            curr.pop_back();
            visited[i] = false;
        }
    }
    
    vector<string> findPermutation(string &s) {
        sort(s.begin(), s.end());
        
        vector<bool> visited(s.size(), false);
        string curr = "";
        
        solve(s, visited, curr);
        
        return ans;
    }
};