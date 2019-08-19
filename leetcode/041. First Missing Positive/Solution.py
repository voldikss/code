# 关键理解：缺失的这个数肯定小于等于 len(nums) + 1
class Solution:
    def firstMissingPositive(self, nums):
        if not 1 in nums:
            return 1

        for i in range(1, len(nums)+2):
            if not i in nums:
                print(i)
                return i


s = Solution()
s.firstMissingPositive([2, 1])
