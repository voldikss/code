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

// 好巧哦
class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), columns = matrix[0].size();
        int row = 0, column = columns - 1;
        while (row < rows && column >= 0) {
            int num = matrix[row][column];
            if (num < target)
                row++;
            else if (num > target)
                column--;
            else
                return true;
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
