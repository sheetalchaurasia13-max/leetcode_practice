class Solution {
private:
    bool dfs(int r, int c, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // If we reach out of bounds, it's not a closed island
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return false;
        }
        
        // If it's water (1), it's a valid boundary for this path
        if (grid[r][c] == 1) {
            return true;
        }
        
        // Mark the current cell as visited by changing it to 1
        grid[r][c] = 1;
        
        // Explore all 4 directions
        bool left = dfs(r, c - 1, grid);
        bool right = dfs(r, c + 1, grid);
        bool up = dfs(r - 1, c, grid);
        bool down = dfs(r + 1, c, grid);
        
        // The island is closed only if all four directions are valid
        return left && right && up && down;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int closedIslands = 0;
        
        // Step 1: Eliminate all land cells connected to the borders
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if ((r == 0 || r == rows - 1 || c == 0 || c == cols - 1) && grid[r][c] == 0) {
                    dfs(r, c, grid);
                }
            }
        }
        
        // Step 2: Count remaining isolated islands
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    // If dfs returns true, it's a closed island
                    if (dfs(r, c, grid)) {
                        closedIslands++;
                    }
                }
            }
        }
        
        return closedIslands;
    }
};