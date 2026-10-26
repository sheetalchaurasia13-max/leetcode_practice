#include <vector>
#include <queue>

class Solution {
public:
    int countIslands(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int validIslandsCount = 0;
        
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If we find land, start a BFS to explore the island
                if (grid[i][j] > 0) {
                    long long islandSum = 0;
                    std::queue<std::pair<int, int>> q;
                    
                    q.push({i, j});
                    islandSum += grid[i][j];
                    grid[i][j] = 0; // Mark as visited
                    
                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        
                        for (int d = 0; d < 4; ++d) {
                            int nr = r + dRow[d];
                            int nc = c + dCol[d];
                            
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                                islandSum += grid[nr][nc];
                                grid[nr][nc] = 0; // Mark as visited
                                q.push({nr, nc});
                            }
                        }
                    }
                    
                    // Check if total value of the island is divisible by k
                    if (islandSum % k == 0) {
                        validIslandsCount++;
                    }
                }
            }
        }
        
        return validIslandsCount;
    }
};