class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        sign = (dividend > 0) ^ (divisor > 0)  # Note: 使用异或运算符好评
        dividend = abs(dividend)
        divisor = abs(divisor)

        # 用两个 while ,好
        res = 0
        while dividend >= divisor:
            tmp, timer = divisor, 1
            while dividend >= tmp:
                dividend -= tmp
                res += timer
                tmp <<= 2
                timer <<= 2

        if sign:
            res = -res

        if res < -2**31 or res > 2**31-1:
            res = 2**31 - 1

        return res


s = Solution()
print(s.divide(987654321, 3))
print(s.divide(9, 3))
print(s.divide(10, 3))
print(s.divide(21, 3))
print(s.divide(2, 3))
print(s.divide(2**31, 1))
