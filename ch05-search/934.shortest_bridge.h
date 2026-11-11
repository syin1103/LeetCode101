/*
 * 934.Shortest Bridge
 */

#include <queue>
#include <utility>
#include <vector>

using std::vector;

class Solution {
  std::vector<int> directions{-1, 0, 1, 0, -1};

 public:
  int shortestBridge(vector<vector<int>>& grid) {
    std::queue<std::pair<int, int>> island;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid.size(); j++) {
        if (grid[i][j] == 1) {
          dfs(i, j, grid, island);
          return bfs(island, grid);
        }
      }
    }
    return 0;
  }

  int bfs(std::queue<std::pair<int, int>>& island,
          std::vector<std::vector<int>>& grid) {
    int dist = -1;
    int n = grid.size();
    while (!island.empty()) {
      dist++;
      int count = island.size();
      while (count--) {
        auto [row, col] = island.front();
        island.pop();
        for (int k = 0; k < directions.size() - 1; k++) {
          int r = row + directions[k], c = col + directions[k + 1];
          if (0 <= r && r < n && 0 <= c && c < n && grid[r][c] != -1) {
            if (grid[r][c] == 1) {
              return dist;
            }

            if (grid[r][c] == 0) {
              grid[r][c] = -1;
              island.push({r, c});
            }
          }
        }
      }
    }
    return dist;  // will not happend
  }

  void dfs(int r, int c, std::vector<std::vector<int>>& grid,
           std::queue<std::pair<int, int>>& island) {
    int n = grid.size();
    grid[r][c] = -1;  // mark to visited
    island.push({r, c});

    for (int k = 0; k < directions.size() - 1; k++) {
      int nr = r + directions[k], nc = c + directions[k + 1];
      if (0 <= nr && nr < n && 0 <= nc && nc < n && grid[nr][nc] == 1) {
        dfs(nr, nc, grid, island);
      }
    }
  }
};