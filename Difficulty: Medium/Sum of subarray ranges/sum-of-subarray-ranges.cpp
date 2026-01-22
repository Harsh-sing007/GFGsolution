class Solution {
public:
    long long subarrayRanges(vector<int>& arr) {
        int n = arr.size();
        vector<int> prevSmaller(n), nextSmaller(n);
        vector<int> prevGreater(n), nextGreater(n);
        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Previous Greater Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sumMin = 0, sumMax = 0;

        for (int i = 0; i < n; i++) {
            long long leftMin = i - prevSmaller[i];
            long long rightMin = nextSmaller[i] - i;
            sumMin += (long long)arr[i] * leftMin * rightMin;

            long long leftMax = i - prevGreater[i];
            long long rightMax = nextGreater[i] - i;
            sumMax += (long long)arr[i] * leftMax * rightMax;
        }

        return sumMax - sumMin;
    }
};
