#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] != word[0]) {
          continue;
        }

        if (backtracking(i, j, board, visited, word, 0)) {
          return true;
        }
      }
    }
    return false;
  }

  bool backtracking(int i, int j, std::vector<std::vector<char>>& board,
                    std::vector<std::vector<bool>>& visited,
                    const std::string& word, int ptr) {
    if (visited[i][j] || board[i][j] != word[ptr]) {
      return false;
    }

    if (ptr == word.size() - 1) {
      return true;
    }

    std::vector<int> directions{-1, 0, 1, 0, -1};
    int m = board.size(), n = board[0].size();

    visited[i][j] = true;
    for (int k = 0; k < directions.size() - 1; k++) {
      int r = i + directions[k], c = j + directions[k + 1];
      if (0 <= r && r < m && 0 <= c && c < n && board[r][c] == word[ptr + 1]) {
        if (backtracking(r, c, board, visited, word, ptr + 1)) {
          return true;
        }
      }
    }
    visited[i][j] = false;
    return false;
  }
};