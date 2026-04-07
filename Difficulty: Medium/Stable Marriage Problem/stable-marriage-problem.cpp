#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();

        vector<int> wife(n, -1);     
        vector<int> husband(n, -1);    
        vector<int> next(n, 0);        
        vector<vector<int>> ranking(n, vector<int>(n));
        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                ranking[w][women[w][i]] = i;
            }
        }

        queue<int> freeMen;
        for (int i = 0; i < n; i++) {
            freeMen.push(i);
        }

        while (!freeMen.empty()) {
            int m = freeMen.front();
            freeMen.pop();

            int w = men[m][next[m]];
            next[m]++;

            if (wife[w] == -1) {
                wife[w] = m;
                husband[m] = w;
            } else {
                int m1 = wife[w];

                if (ranking[w][m] < ranking[w][m1]) {
                    wife[w] = m;
                    husband[m] = w;
                    husband[m1] = -1;
                    freeMen.push(m1);
                } else {
                    freeMen.push(m);
                }
            }
        }

        return husband;
    }
};