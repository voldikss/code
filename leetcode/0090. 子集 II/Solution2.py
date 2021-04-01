from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []
        nums.sort()
        res = [[]]
        cur = []
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                cur = [tmp + [nums[i]] for tmp in cur]
            else:
                cur = [tmp + [nums[i]] for tmp in res]

            res += cur

        return res


s = Solution()
# res = s.subsetsWithDup([1, 2, 3])
res = s.subsetsWithDup([1, 2, 2])
print(res)
print(len(res))
