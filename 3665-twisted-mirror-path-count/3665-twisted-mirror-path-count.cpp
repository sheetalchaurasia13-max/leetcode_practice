class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<vector<int>> R(m + 2, vector<int>(n + 2, 0));
        vector<vector<int>> D(m + 2, vector<int>(n + 2, 0));

        // start at (0,0), which is empty
        R[0][1] = 1;
        D[1][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int r = R[i][j], d = D[i][j];
                if (i == m - 1 && j == n - 1) {
                    return (r + d) % MOD;
                }
                if (grid[i][j] == 0) {
                    int t = (r + d) % MOD;
                    if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + t) % MOD;
                    if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + t) % MOD;
                } else {
                    // mirror: moving right -> goes down, moving down -> goes right
                    if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + r) % MOD;
                    if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + d) % MOD;
                }
            }
        }
        return 0;
    }
};