constexpr int mod = 1000000007;
int row[500];

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int N = size(grid), M = size(grid[0]);
        memset(row, 0, M * sizeof *row);
        row[0] = 1;

        for (const auto &r : grid) {
            for (int i = 0, prv = 0; i < M; ++i) {
                if (r[i]) swap(prv, row[i]); else row[i] = prv = (prv + row[i]) % mod;
            }
        }
        return row[M-1];
    }
};