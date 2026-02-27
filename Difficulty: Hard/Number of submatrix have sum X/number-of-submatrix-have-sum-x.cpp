#include <vector>
using namespace std;

class Solution {
public:

    int countSquare(vector<vector<int>>& mat, int X) {

        int n = mat.size();
        int m = mat[0].size();

        int count = 0;

        // Prefix Sum Matrix
        vector<vector<int>> prefix(n+1, vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                prefix[i][j] = mat[i-1][j-1]
                              + prefix[i-1][j]
                              + prefix[i][j-1]
                              - prefix[i-1][j-1];
            }
        }

        // Check all square submatrices
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                for(int size=1; i+size<=n && j+size<=m; size++){

                    int r = i+size;
                    int c = j+size;

                    int sum = prefix[r][c]
                             - prefix[i][c]
                             - prefix[r][j]
                             + prefix[i][j];

                    if(sum == X)
                        count++;
                }
            }
        }

        return count;
    }
};