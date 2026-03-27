#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChocolate(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> front(m, vector<int>(m, 0)), curr(m, vector<int>(m, 0));

        // Base case (last row)
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2)
                    front[j1][j2] = grid[n-1][j1];
                else
                    front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        // DP from bottom to top
        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {

                    int maxi = -1e9;

                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {

                            int value = 0;

                            if (j1 == j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1] + grid[i][j2];

                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;

                            if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m)
                                value += front[nj1][nj2];
                            else
                                value += -1e9;

                            maxi = max(maxi, value);
                        }
                    }

                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }

        return front[0][m-1];
    }
};