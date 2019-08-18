# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def rightSideView(self, root):
        res = []
        if not root: return res
        # 使用 stack 保存路径
        stack = [(root, 1)]
        while stack:
            (node, depth) = stack.pop()
            if (depth > len(res)): res.append(node.val)
            if (node.left): stack.append((node.left, depth + 1))
            if (node.right): stack.append((node.right, depth + 1))

        return res
