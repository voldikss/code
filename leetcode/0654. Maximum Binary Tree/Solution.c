//============================================================================
// FileName: Solution.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int findMaxPos(int *nums, int begin, int end) {
    int pos = begin;
    int max_v = nums[begin];
    for (int i = begin; i <= end; ++i) {
        if (nums[i] > max_v) {
            max_v = nums[i];
            pos = i;
        }
    }
    return pos;
}

struct TreeNode *helper(int *nums, int begin, int end) {
    if (begin > end) return NULL;
    int pos = findMaxPos(nums, begin, end);
    struct TreeNode *p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->val = nums[pos];
    p->left = helper(nums, begin, pos - 1);
    p->right = helper(nums, pos + 1, end);
    return p;
}

struct TreeNode *constructMaximumBinaryTree(int *nums, int numsSize) {
    if (numsSize == 0) return NULL;
    return helper(nums, 0, numsSize - 1);
}

int main() {

    return 0;
}
