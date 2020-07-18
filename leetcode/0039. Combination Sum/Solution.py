from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def helper(nums1, nums2):
            if sum(nums1) == target:
                res.append(nums1)
                return
            elif sum(nums1) > target:
                return

            for i in range(len(nums2)):
                nums = nums1.copy()
                nums.append(nums2[i])
                helper(nums, nums2[i:])

        res = []
        candidates.sort()
        helper([], candidates)
        return res


s = Solution()
print(s.combinationSum([2, 3, 6, 7], 7))
print(s.combinationSum([], 7))
