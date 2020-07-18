class Solution:
    # first accepted version
    def removeElement(self, nums, val):
        if not nums:
            return 0
        times = 0
        for _ in range(len(nums)):
            count = 0
            flag = False
            for i in range(len(nums)):
                if nums[i] == val:
                    flag = True
                    count += 1
                if flag and i != len(nums)-1:
                    nums[i] = nums[i+1]
            if count > times:
                times = count

        return len(nums) - times

    def removeElement_v2(self, nums, val):
        if not nums:
            return 0
        while True:
            try:
                index = nums.index(val)
                nums.pop(index)
            except:
                return len(nums)

    def removeElement_v3(self, nums, val):
        if not nums:
            return 0

        tail = 0
        for index in range(len(nums)):
            if nums[index] != val:
                nums[tail] = nums[index]
                tail += 1
        return tail 


nums = [0, 1, 2, 2, 3, 0, 4, 2]
val = 2
s = Solution()
print(s.removeElement_v3(nums, val))
print(nums)
