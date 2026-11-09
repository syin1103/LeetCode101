/*
 * 77.Combinations
 */

#include <vector>

using std::vector;

class Solution {
 public:
  void backtracking(int pos, int k, int n, vector<int>& pick,
                    vector<vector<int>>& res) {
    if (k <= 0) {
      res.push_back(pick);
      return;
    }

    for (int i = pos; i <= n - k + 1; i++) {
      pick.push_back(i);
      backtracking(i + 1, k - 1, n, pick, res);
      pick.pop_back();
    }
    return;
  }

  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> pick;
    backtracking(1, k, n, pick, res);
    return res;
  }
};