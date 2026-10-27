class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // Initialize the grid with '#' (obstacles)
        vector<string> grid(m, string(n, '#'));
        
        // Make the entire first row free
        for (int j = 0; j < n; ++j) {
            grid[0][j] = '.';
        }
        
        // Make the entire last column free
        for (int i = 0; i < m; ++i) {
            grid[i][n - 1] = '.';
        }
        
        return grid;
    }
};