class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        vector<int> st;

        for (int x : arr) {
            bool removed = false;

            while (!st.empty() && (st.back() * x < 0)) {
                int top = st.back();

                if (abs(top) == abs(x)) {
                    st.pop_back();   // both removed
                    removed = true;
                    break;
                }
                else if (abs(top) > abs(x)) {
                    // x gets removed
                    removed = true;
                    break;
                }
                else {
                    // top gets removed
                    st.pop_back();
                }
            }

            if (!removed) {
                st.push_back(x);
            }
        }

        return st;
    }
};