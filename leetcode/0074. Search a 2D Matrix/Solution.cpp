#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;

        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] > target) break;
            if (matrix[i][0] <= target && matrix[i][n - 1] >= target) {
                int left = 0;
                int right = n - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (matrix[i][mid] > target)
                        right = mid - 1;
                    else if (matrix[i][mid] < target)
                        left = mid + 1;
                    else
                        return true;
                }
                break;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    // vector<vector<int>> matrix = {{1, 3, 5, 7},
    //                               {10, 11, 16, 20},
    //                               {23, 30, 34, 50}};
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 50}};
    cout << s.searchMatrix(matrix, 13) << endl;
    return 0;
}
