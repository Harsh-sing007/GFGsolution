class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Find max element row index in mid column
            int maxRow = 0;
            for (int i = 1; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            int leftVal  = (mid > 0)     ? mat[maxRow][mid - 1] : INT_MIN;
            int rightVal = (mid < n - 1) ? mat[maxRow][mid + 1] : INT_MIN;

            // GFG allows >= comparison
            if (mat[maxRow][mid] >= leftVal && mat[maxRow][mid] >= rightVal) {
                return {maxRow, mid};
            }
            else if (leftVal > mat[maxRow][mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return {-1, -1}; // fallback (won’t be used)
    }
};
