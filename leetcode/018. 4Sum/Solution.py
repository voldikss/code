from typing import List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        end = len(nums) - 1
        res = []
        for i in range(end):
            for j in range(i + 1, end):
                lp = j + 1
                rp = end
                while lp < rp:
                    sum = nums[i] + nums[j] + nums[lp] + nums[rp]
                    if sum < target:
                        lp += 1
                    elif sum > target:
                        rp -= 1
                    else:
                        tmp = [nums[i], nums[j], nums[lp], nums[rp]]
                        if tmp not in res:
                            res.append([nums[i], nums[j], nums[lp], nums[rp]])
                        lv = nums[lp]
                        while nums[lp] == lv and lp < rp:
                            lp += 1
                        rv = nums[rp]
                        while nums[rp] == rv and lp < rp:
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
assert s.fourSum([1, -2, -5, -4, -3, 3, 3, 5], -11)
