#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  vector<vector<string>> res;
  void backtracking(int n, int row, vector<string>& path, vector<bool>& col,
                    vector<bool>& ldiag, vector<bool>& rdiag) {
    if (row == n) {
      res.push_back(path);
      return;
    }

    for (int i = 0; i < n; i++) {
      if (!col[i] && !ldiag[i - row + n - 1] && !rdiag[row + i]) {
        path[row][i] = 'Q';
        col[i] = ldiag[i - row + n - 1] = rdiag[row + i] = true;

        backtracking(n, row + 1, path, col, ldiag, rdiag);

        path[row][i] = '.';
        col[i] = ldiag[i - row + n - 1] = rdiag[row + i] = false;
      }
    }
    return;
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<string> path(n, string(n, '.'));
    vector<bool> col(n, false);
    vector<bool> ldiag(2 * n - 1, false);
    vector<bool> rdiag(2 * n - 1, false);

    backtracking(n, 0, path, col, ldiag, rdiag);
    return res;
  }
};