
class Solution {
 public:
  int findCircleNum(std::vector<std::vector<int>>& isConnected) {
    std::vector<bool> visited(isConnected[0].size(), false);
    int count = 0;

    for (int i = 0; i < isConnected.size(); i++) {
      if (!visited[i]) {
        dfs(i, isConnected, visited);
        count++;
      }
    }
    return count;
  }

  void dfs(int i, std::vector<std::vector<int>>& isConnected,
           std::vector<bool>& visited) {
    if (visited[i]) return;

    visited[i] = true;
    for (int j = 0; j < isConnected[0].size(); j++) {
      if (isConnected[i][j] == 1) {
        dfs(j, isConnected, visited);
      }
    }
  }
};