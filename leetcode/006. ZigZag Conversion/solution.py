class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        """
        碰到边界后反向
        """
        if numRows == 1 or len(s) < numRows:
            return s
        res = [""] * numRows
        index = 0
        mark = 1
        for i in s:
            res[index] += i
            if index == numRows - 1:
                mark = -1
            if index == 0:
                mark = 1
            index += mark
        
        return "".join(res)


class Solution2:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        """
        解法一的优化版，耗时貌似没怎么变，但是写法优雅.
        """
        if numRows == 1 or len(s) < numRows:
            return s
        res = [""] * numRows
        index = 0
        mark = 1
        for i in s:
            res[index] += i
            index += mark
            if index == numRows - 1 or index == 0:
                mark *= -1
        
        return "".join(res)


class Solution3:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        """
        室友 lzl 的解法
        """
        if numRows == 1 or len(s) < numRows:
            return s
        res = [""] * numRows
        for i, j in enumerate(s):
            remainder = i % (2 * numRows - 2)
            if remainder >= numRows:
                remainder = 2 * numRows - 2 - remainder
            res[remainder] += j
        
        return "".join(res)


s = Solution3()
print(s.convert("PAYPALISHIRING", 3))
# print(s.convert("ABC", 1))
