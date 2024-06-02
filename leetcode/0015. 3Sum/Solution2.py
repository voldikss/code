class Solution:
    def threeSum(self, nums):
        res = []
        nums.sort()
        for i in range(len(nums)-2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            left = i + 1
            right = len(nums) - 1
            while left < right:
                sum = nums[i] + nums[left] + nums[right]
                if sum < 0:
                    left += 1
                elif sum > 0:
                    right -= 1
                else:
                    res.append([nums[i], nums[left], nums[right]])
                    while left < right and nums[left+1] == nums[left]:
                        left += 1

                    while left < right and nums[right-1] == nums[right]:
                        right -= 1

                    left += 1
                    right -= 1
        return res


nums = [-2, 0, 0, 2, 2]
s = Solution()
result = s.threeSum(nums)
print(result)

# a = [1,2,3,4,5,6,7,8,9]
# b = [[1,2,3,4,5,6,7,8,9], 3]
# a in b
