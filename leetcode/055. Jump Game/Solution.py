from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True
        pos = len(nums) - 1
        has_0 = False
        while pos >= 0:
            if nums[pos] == 0:
                if not has_0:
                    has_0 = True
                    tmp = pos
            elif has_0:
                if nums[pos] > tmp - pos:
                    has_0 = False
                elif nums[pos] == tmp - pos and tmp == len(nums) - 1:
                    has_0 = False
            pos -= 1

        return not has_0


s = Solution()
# print(s.canJump([0]))
# print(s.canJump([3,2,1,0,4]))
print(s.canJump([2, 0, 0]))
# print(s.canJump([2, 3, 1, 1, 4]))
# print(s.canJump([3, 2, 1, 0, 4]))
# print(s.canJump([2, 0]))
