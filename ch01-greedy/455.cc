
// 455.Assign Cookies
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  int findContentChildren(vector<int>& children, vector<int>& cookies) {
    std::sort(children.begin(), children.end());
    std::sort(cookies.begin(), cookies.end());

    int child_i = 0, cookies_j = 0;
    while (child_i < children.size() && cookies_j < cookies.size()) {
      if (children[child_i] <= cookies[cookies_j]) {
        ++child_i;
      }
      ++cookies_j;
    }
    return child_i;
  }
};