class Solution {
public:
    void rearrangeQueue(queue<int>& q) {
        int n = q.size();
        int half = n / 2;
        stack<int> st;

        // Step 1: Push first half into stack
        for (int i = 0; i < half; i++) {
            st.push(q.front());
            q.pop();
        }

        // Step 2: Push stack elements back to queue
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        // Step 3: Move first half elements to back
        for (int i = 0; i < half; i++) {
            q.push(q.front());
            q.pop();
        }

        // Step 4: Push first half again into stack
        for (int i = 0; i < half; i++) {
            st.push(q.front());
            q.pop();
        }

        // Step 5: Interleave both halves
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
            q.push(q.front());
            q.pop();
        }
    }
};
