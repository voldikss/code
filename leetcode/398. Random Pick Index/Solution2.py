# online 处理
from random import randint


class Solution:

    def __init__(self, nums):
        self.nums = nums

    def pick(self, target):
        n = 0
        index = -1
        for idx, num in enumerate(self.nums):
            if num == target:
                n += 1
                if randint(1, n) == n:
                    index = idx
        return index


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
