/*
 * 1091.Shortest Path in Binary Matrix
 */

#include <queue>
#include <utility>
#include <vector>

using std::vector;

class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 1) {
      return grid[0][0] == 0 ? 1 : -1;
    }

    if (grid[0][0] == 1) {
      return -1;
    }

    std::queue<std::pair<int, int>> que;
    int dist = 0;

    que.push({0, 0});
    grid[0][0] = -1;

    while (!que.empty()) {
      dist++;
      int count = que.size();
      while (count--) {
        auto [row, col] = que.front();
        que.pop();

        if (row == n - 1 && col == n - 1) {
          return dist;
        }

        for (int dx = -1; dx <= 1; dx++) {
          for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) {
              continue;
            }

            int nr = row + dx, nc = col + dy;
            if (0 <= nr && nr < n && 0 <= nc && nc < n && grid[nr][nc] == 0) {
              que.push({nr, nc});
              grid[nr][nc] = -1;
            }
          }
        }
      }
    }

    return -1;
  }
};