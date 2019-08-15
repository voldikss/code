class Solution:
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        tmp = nums[:]
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                nums[i] = nums[i + 1]
                break
        if nums == sorted(nums):
            return True
        else:
            for i in range(len(tmp) - 1):
                if tmp[i] > tmp[i + 1]:
                    tmp[i + 1] = tmp[i]
                    break
            if tmp == sorted(tmp):
                return True
            else:
                return False
