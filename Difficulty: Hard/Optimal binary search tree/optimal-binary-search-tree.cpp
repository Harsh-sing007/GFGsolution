class Solution {
public:
    int minCost(vector<int> &keys, vector<int> &freq)
    {
        int n = keys.size();
        int cost[n][n];

        // Base case: single key
        for (int i = 0; i < n; i++)
            cost[i][i] = freq[i];

        // L = chain length
        for (int L = 2; L <= n; L++)
        {
            for (int i = 0; i <= n - L; i++)
            {
                int j = i + L - 1;
                cost[i][j] = INT_MAX;

                // Compute sum of freq[i..j]
                int sum = 0;
                for (int k = i; k <= j; k++)
                    sum += freq[k];

                // Try every key as root
                for (int r = i; r <= j; r++)
                {
                    int left  = (r > i) ? cost[i][r - 1] : 0;
                    int right = (r < j) ? cost[r + 1][j] : 0;

                    int curr = left + right + sum;

                    if (curr < cost[i][j])
                        cost[i][j] = curr;
                }
            }
        }

        return cost[0][n - 1];
    }
};
