class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++) {

            // Remove elements out of this window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove smaller elements (they are useless)
            while (!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();

            // Add current index
            dq.push_back(i);

            // Window formed
            if (i >= k - 1)
                ans.push_back(arr[dq.front()]);
        }

        return ans;
    }
};
