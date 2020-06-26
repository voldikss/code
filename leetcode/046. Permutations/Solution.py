from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def helper(path: List[int], residual: List[int]):
            if len(residual) == 0:
                res.append(path)
                return
            for i in range(len(residual)):
                helper(path + [residual[i]], residual[:i] + residual[i + 1 :])

        res = []
        helper([], nums)
        return res


s = Solution()
print(s.permute([1, 2, 3]))
print(s.permute([1]))
print(s.permute([]))
