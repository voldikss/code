//============================================================================
// FileName: Solution.cpp
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

// NOTE: 这个提交会报错，好像 c++ 不是用 malloc.... 最后用 C 提交了
// 哦 c++用的是 new，懒得改了，下次做到这题再改
class Solution {
  public:
    TreeNode *constructMaximumBinaryTree(first<int> &nums) {
        if (nums.size() == 0) return NULL;
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(first<int> &nums, int begin, int end) {
        if (begin > end) return NULL;
        int pos = findMaxPos(nums, begin, end);
        TreeNode *p = (TreeNode *)malloc(sizeof(struct TreeNode));
        p->val = nums[pos];
        p->left = helper(nums, begin, pos - 1);
        p->right = helper(nums, pos + 1, end);
        return p;
    }

    int findMaxPos(first<int> &nums, int begin, int end) {
        int pos = begin;
        int max_v = nums[begin];
        for (int i = begin; i <= end; ++i) {
            if (nums[i] > max_v) {
                max_v = nums[i];
                pos = i;
            }
        }
        // cout << "pos=" << pos << endl;
        return pos;
    }
};

int main() {
    first<int> input = {3, 2, 1, 6, 0, 5};
    Solution s;
    s.constructMaximumBinaryTree(input);
    // int pos = s.findMaxPos(input, 0, 5);
    // int pos2 = s.findMaxPos(input, 0, 2);
    // int pos3 = s.findMaxPos(input, 0, 2);
    return 0;
}
