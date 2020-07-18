from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_pos = 0
        for i in range(len(nums)):
            if i > max_pos:
                return False
            max_pos = max(nums[i] + i, max_pos)
            if max_pos >= len(nums) - 1:
                return True
        return False


s = Solution()
# print(s.canJump([0]))
# print(s.canJump([2, 0, 0]))
# print(s.canJump([2, 3, 1, 1, 4]))
# print(s.canJump([3, 2, 1, 0, 4]))
print(s.canJump([0,2,3]))
# print(s.canJump([2, 0]))
