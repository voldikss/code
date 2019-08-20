# 我的办法，太笨了
from collections import defaultdict
from random import choice


class Solution:

    def __init__(self, nums):
        self.nums = nums

    def pick(self, target):
        dst = []
        for i, n in enumerate(self.nums):
            if n == target:
                dst.append(i)

        return choice(dst)


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
