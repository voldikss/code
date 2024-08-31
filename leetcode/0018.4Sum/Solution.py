from typing import List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        res = []
        for i in range(len(nums) - 3):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, len(nums) - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                lp = j + 1
                rp = len(nums) - 1
                if (nums[i] + nums[j] + nums[lp] + nums[lp + 1]) > target:
                    continue
                if (nums[i] + nums[j] + nums[rp] + nums[rp - 1]) < target:
                    continue
                while lp < rp:
                    sum = nums[i] + nums[j] + nums[lp] + nums[rp]
                    if sum < target:
                        lp += 1
                    elif sum > target:
                        rp -= 1
                    else:
                        res.append([nums[i], nums[j], nums[lp], nums[rp]])
                        while lp < rp and nums[lp] == nums[lp + 1]:
                            lp += 1
                        while lp < rp and nums[rp] == nums[rp - 1]:
                            rp -= 1
                        lp += 1
                        rp -= 1
        return res


s = Solution()
assert s.fourSum([1, 0, -1, 0, -2, 2], 0) == [
    [-2, -1, 1, 2],
    [-2, 0, 0, 2],
    [-1, 0, 0, 1],
]
assert s.fourSum([-3, -2, -1, 0, 0, 1, 2, 3], 0) == [
    [-3, -2, 2, 3],
    [-3, -1, 1, 3],
    [-3, 0, 0, 3],
    [-3, 0, 1, 2],
    [-2, -1, 0, 3],
    [-2, -1, 1, 2],
    [-2, 0, 0, 2],
    [-1, 0, 0, 1],
]
assert s.fourSum([0, 0, 0, 0], 0) == [[0, 0, 0, 0]]
# assert s.fourSum([1, -2, -5, -4, -3, 3, 3, 5], -11)
