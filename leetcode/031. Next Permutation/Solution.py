class Solution:
    def nextPermutation(self, nums):
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) <= 1:
            return
        for i in range(len(nums) - 1, -1, -1):
            num1 = nums[i]
            for j in range(len(nums) - 1, i, -1):
                num2 = nums[j]
                if (num2 > num1):
                    nums[i] = num2
                    nums[j] = num1
                    tmp = sorted(nums[i+1:])
                    for k in range(len(tmp)):
                        nums[i+k+1] = tmp[k]
                    # print(nums)
                    return
        if i == 0:
            nums.sort()
            # print(nums)


s = Solution()
samples = [
    # [1],
    # [1, 2],
    # [1, 2, 3],
    [3, 2, 1],
    # [1, 3, 2],
    # [1, 1, 5],
    # [1, 2, 4, 5, 3]
]
for i in samples:
    s.nextPermutation_v2(i)
