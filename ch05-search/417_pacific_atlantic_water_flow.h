/*
 * 417.Pacific Atlantic Water Flow
 */

#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    std::vector<std::vector<bool>> pacific(m, std::vector<bool>(n, false));
    std::vector<std::vector<bool>> atlantic(m, std::vector<bool>(n, false));
    std::vector<std::vector<int>> res;

    for (int i = 0; i < m; i++) {
      dfs(i, 0, heights, pacific);
      dfs(i, n - 1, heights, atlantic);
    }

    for (int j = 0; j < n; j++) {
      dfs(0, j, heights, pacific);
      dfs(m - 1, j, heights, atlantic);
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (pacific[i][j] && atlantic[i][j]) {
          res.push_back({i, j});
        }
      }
    }
    return res;
  }

  void dfs(int i, int j, std::vector<std::vector<int>>& heights,
           std::vector<std::vector<bool>>& reach) {
    if (reach[i][j]) {
      return;
    }

    std::vector<int> direction{-1, 0, 1, 0, -1};
    for (int k = 0; k < direction.size() - 1; k++) {
      reach[i][j] = true;
      int r = i + direction[k], c = j + direction[k + 1];
      if (0 <= r && r < heights.size() && 0 <= c && c < heights[0].size() &&
          heights[i][j] <= heights[r][c] && !reach[r][c]) {
        dfs(r, c, heights, reach);
      }
    }
    return;
  }
};