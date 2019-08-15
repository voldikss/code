class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend < divisor and dividend >= 0 and divisor >= 0:
            return 0
        if dividend == divisor:
            return 1
        if dividend == -divisor:
            return -1
        #######################################

        sign = (dividend > 0) ^ (divisor > 0)  # Note: 使用异或运算符好评
        dividend = abs(dividend)
        divisor = abs(divisor)

        #######################################
        timer = 1
        tmp_divisor = divisor
        while dividend > tmp_divisor:
            tmp_divisor <<= 1
            timer <<= 1

        tmp_divisor >>= 1
        timer >>= 1

        if dividend > tmp_divisor:
            dividend -= tmp_divisor

        # print(dividend, divisor, timer)
        res = timer + self.divide(dividend, divisor)

        ###################################
        if sign:
            res = -res

        if res < -2**31 or res > 2**31-1:
            res = 2**31 - 1

        return res


s = Solution()
print(s.divide(-1, 1))
print(s.divide(1, 1))
print(s.divide(35, 3))
print(s.divide(987654321, 3))
print(s.divide(9, 3))
print(s.divide(10, 3))
print(s.divide(21, 3))
print(s.divide(2, 3))
print(s.divide(2**31, 1))
print(s.divide(1004958205, -2137325331))
print(s.divide(-3, 10))
