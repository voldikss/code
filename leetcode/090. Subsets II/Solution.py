from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        def dfs(path, index):
            if index > len(nums):
                return
            res.add(tuple(path[::]))

            for i in range(index, len(nums)):
                path.append(nums[i])
                dfs(path, i + 1)
                path.pop()

        res = set()
        nums.sort()
        dfs([], 0)
        return list(map(lambda t: list(t), res))


s = Solution()
# res = s.subsetsWithDup([1, 2, 3])
res = s.subsetsWithDup([1, 2, 2])
print(res)
print(len(res))
