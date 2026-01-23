class Solution {
public:
    int maxPeople(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftBlock(n, -1), rightBlock(n, n);
        stack<int> st;

        // Nearest Greater or Equal to Left
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (!st.empty()) leftBlock[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Nearest Greater or Equal to Right
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (!st.empty()) rightBlock[i] = st.top();
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int leftVisible = i - leftBlock[i] - 1;
            int rightVisible = rightBlock[i] - i - 1;
            ans = max(ans, leftVisible + rightVisible + 1);
        }
        return ans;
    }
};
