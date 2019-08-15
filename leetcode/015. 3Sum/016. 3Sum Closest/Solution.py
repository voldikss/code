class Solution:
    def threeSumClosest(self, nums, target):
        diff = -1
        nums.sort()
        for i in range(len(nums) - 2):
            left = i+1
            right = len(nums) - 1
            while left < right:
                print(nums[i], nums[left], nums[right])
                curr_sum = nums[i] + nums[left] + nums[right]
                if curr_sum == target:
                    return curr_sum
                else:
                    if curr_sum < target:
                        left += 1
                    else:
                        right -= 1

                    curr_diff = abs(curr_sum - target)

                    if diff < 0:
                        diff = curr_diff
                        sum = curr_sum

                    elif curr_diff < diff:
                        diff = curr_diff
                        sum = curr_sum
        return sum


s = Solution()
nums = [-5, -3, -2, -1, -1, 0, 0, 4, 4, 5]
result = s.threeSumClosest(nums, 1)
print(result)
