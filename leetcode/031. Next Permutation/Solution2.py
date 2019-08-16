class Solution:
    def nextPermutation(self, nums):
        if len(nums) <= 1:
            return

        found = False
        for i in range(len(nums)-1, 0, -1):
            if nums[i] > nums[i-1]:
                found = True
                break

        if i == 1 and found == False:
            nums.reverse()
            # print(nums)
            return

        for j in range(len(nums)-1, 0, -1):
            if nums[j] > nums[i-1]:
                tmp = nums[i-1]
                nums[i-1] = nums[j]
                nums[j] = tmp
                break

        tmp = list(reversed(nums[i:]))
        for k in range(len(list(tmp))):
            nums[i+k] = tmp[k]

        print(nums)


s = Solution()
samples = [
    # [1],
    # [1, 2],
    # [1, 2, 3],
    [3, 2, 1],
    # [1, 3, 2],
    # [1, 1, 5],
    [1, 2, 4, 5, 3]
]
for i in samples:
    s.nextPermutation(i)
