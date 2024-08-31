class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        maxA = 0
        tmp = 0
        for i in range(len(height)):
            if height[i] <= tmp:
                continue
            else:
                tmp = height[i]
            for j in range(len(height) - 1, i, -1):
                if height[j] >= height[i]:
                    curr = height[i] * (j - i)
                    if curr > maxA:
                        maxA = curr
                    break
                else:
                    curr = height[j] * (j - i)
                    if curr > maxA:
                        maxA = curr
        
        return maxA


height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
s = Solution()
print(s.maxArea(height))
