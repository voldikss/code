class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if -(nums[i] + nums[j]) in nums[j+1:]:
                    res.append([nums[i], nums[j], -(nums[i] + nums[j])])
        
        return res


nums1 = [-1, 0, 1, 2, -1, -4]

s = Solution()
print(s.threeSum(nums1))
