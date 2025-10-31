class Solution {
public:
    string firstRepChar(string s) {
        vector<bool> seen(26, false); // For 26 lowercase letters

        for (char c : s) {
            if (seen[c - 'a'])  // If already seen before
                return string(1, c);
            seen[c - 'a'] = true;
        }
        return "-1"; // No repetition found
    }
};
