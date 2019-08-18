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
        queue = [root]
        while queue:
            res.append(queue[-1].val)
            size = len(queue)
            for i in range(size):
                head = queue.pop(0)
                if (head.left): queue.append(head.left)
                if (head.right): queue.append(head.right)
        return res
