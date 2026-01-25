#include <iostream>
#include <stack>
#include <vector>

using std::vector;
class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    std::vector<int> direction{-1, 0, 1, 0, -1};
    int row = grid.size(), col = grid[0].size(), max_area = 0;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == 1) {
          std::stack<std::pair<int, int>> stk;

          int area = 1;
          grid[i][j] = 0;
          stk.push({i, j});
          while (!stk.empty()) {
            auto pos = stk.top();
            stk.pop();
            for (int k = 0; k < 4; k++) {
              int r = pos.first + direction[k];
              int c = pos.second + direction[k + 1];
              if (0 <= r && r < row && 0 <= c && c < col && grid[r][c] == 1) {
                area += 1;
                grid[r][c] = 0;
                stk.push({r, c});
              }
            }
          }
          max_area = std::max(max_area, area);
        }
      }
    }
    return max_area;
  }
};

int main() {
  std::vector<std::vector<int>> grid = {
      {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
      {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
      {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

  std::cout << Solution().maxAreaOfIsland(grid) << std::endl;
  return 0;
}