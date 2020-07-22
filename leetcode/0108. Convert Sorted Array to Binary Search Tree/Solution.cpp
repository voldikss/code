#include "../../vital/binary_tree.cpp"
#include "../../vital/vector.cpp"
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
#include <variant>
#include <vector>
using namespace std;

class Solution {
  public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return this->helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(vector<int> &nums, int l, int r) {
        if (l > r) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = this->helper(nums, l, mid - 1);
        node->right = this->helper(nums, mid + 1, r);
        return node;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-10, -3, 0, 5, 9};
    auto res = s.sortedArrayToBST(nums);
    cout << res << endl;
    return 0;
}
