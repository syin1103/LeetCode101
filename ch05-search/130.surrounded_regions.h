/*
 * 130.Surrounded Regions
 */

#include <vector>

using std::vector;

class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++) {
      dfs(i, 0, board);
      dfs(i, n - 1, board);
    }

    for (int j = 0; j < n; j++) {
      dfs(0, j, board);
      dfs(m - 1, j, board);
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        } else if (board[i][j] == '1') {
          board[i][j] = 'O';
        }
      }
    }
  }

  void dfs(int r, int c, std::vector<std::vector<char>>& board) {
    if (board[r][c] == 'X' || board[r][c] == '1') {
      return;
    }

    board[r][c] = '1';

    std::vector<int> directions{-1, 0, 1, 0, -1};
    int m = board.size(), n = board[0].size();
    for (int k = 0; k < directions.size() - 1; k++) {
      int nr = r + directions[k], nc = c + directions[k + 1];
      if (0 <= nr && nr < m && 0 <= nc && nc < n && board[nr][nc] == 'O') {
        dfs(nr, nc, board);
      }
    }
  }
};