class Solution {
public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Catalan numbers
        vector<int> catalan(n + 1, 0);
        catalan[0] = catalan[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }

        // Step 2: Sort array
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        // Step 3: Map value → result
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int left = i;
            int right = n - i - 1;
            mp[sorted[i]] = catalan[left] * catalan[right];
        }

        // Step 4: Build result
        vector<int> ans;
        for (int x : arr) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};