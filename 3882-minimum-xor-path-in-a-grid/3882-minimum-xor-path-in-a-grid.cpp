#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Max value of grid[i][j] is 1023 (< 1024), so max XOR value is < 2048.
        // dp[j] will store the bitset of possible XOR values for the current row at column j.
        vector<bitset<2048>> dp(n);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bitset<2048> reachable;
                
                if (i > 0) {
                    // Coming from top
                    reachable |= dp[j];
                }
                if (j > 0) {
                    // Coming from left
                    reachable |= dp[j - 1];
                }
                
                if (i == 0 && j == 0) {
                    reachable.set(grid[0][0]);
                } else {
                    bitset<2048> next_reachable;
                    for (int x = 0; x < 2048; ++x) {
                        if (reachable[x]) {
                            next_reachable.set(x ^ grid[i][j]);
                        }
                    }
                    reachable = next_reachable;
                }
                
                dp[j] = reachable;
            }
        }
        
        // Find the smallest x such that dp[n-1][x] is true
        for (int x = 0; x < 2048; ++x) {
            if (dp[n - 1][x]) {
                return x;
            }
        }
        
        return 0;
    }
};