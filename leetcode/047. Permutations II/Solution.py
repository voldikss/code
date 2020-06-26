from typing import List


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        def helper(path: List[int], residual: List[int]):
            if len(path) == len(nums):
                res.append(path)
                return

            for i in range(len(residual)):
                # “这个套路，我曾用过的”
                if i > 0 and residual[i] == residual[i - 1]:
                    continue
                helper(path + [residual[i]], residual[:i] + residual[i + 1 :])

        res = []
        nums.sort()
        helper([], nums)
        return res


s = Solution()
# print(s.permuteUnique([1, 2, 3]))
# print(s.permuteUnique([1, 1, 2]))
print(s.permuteUnique([3,3,0,3]))
