from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        def dfs(path, index):
            res.append(path[::])
            if index >= len(nums):
                return

            for i in range(index, len(nums)):
                if i > index and nums[i - 1] == nums[i]:
                    continue
                path.append(nums[i])
                dfs(path, i + 1)
                path.pop()

        res = []
        nums.sort()
        dfs([], 0)
        return res


s = Solution()
# res = s.subsetsWithDup([1, 2, 3])
res = s.subsetsWithDup([1, 2, 2])
print(res)
print(len(res))
