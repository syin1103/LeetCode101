/*
 * 46.Permulations
 */

#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    std::vector<std::vector<int>> permulations;
    backtracking(0, nums, permulations);
    return permulations;
  }

  void backtracking(int pos, std::vector<int>& nums,
                    std::vector<std::vector<int>>& permulations) {
    if (pos == nums.size() - 1) {
      permulations.push_back(nums);
      return;
    }

    for (int i = pos; i < nums.size(); i++) {
      std::swap(nums[pos], nums[i]);
      backtracking(pos + 1, nums, permulations);
      std::swap(nums[pos], nums[i]);
    }
    return;
  }
};

// another solution

/*
class Solution {
public:
    void backtracking(vector<int>& path, vector<bool>& visited,
                      vector<vector<int>>& res, const vector<int>& nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i ++) {
            if (visited[i]) {
                continue;
            }
            path.push_back(nums[i]);
            visited[i] = true;
            backtracking(path, visited, res, nums);
            visited[i] = false;
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        vector<int> path;
        backtracking(path, visited, res, nums);
        return res;
    }
};

*/