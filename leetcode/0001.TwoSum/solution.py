class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        temp = {}
        for i in range(len(nums)):
            if target - nums[i] in temp:
                return [temp[target - nums[i]], i]
            else:
                temp[nums[i]] = i
