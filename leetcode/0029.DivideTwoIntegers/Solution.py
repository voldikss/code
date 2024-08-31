class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        sign = (dividend > 0) ^ (divisor > 0)  # Note: 使用异或运算符好评
        res = ''

        dividend = abs(dividend)
        divisor = abs(divisor)
        ##########################################
        str_dividend = str(dividend)
        str_divisor = str(divisor)
        quotient, remainder = self.simpleDevide(
            int(str_dividend[:len(str_divisor)+1]), divisor)

        res += str(quotient)
        remainder = str(remainder)

        pos = len(str_divisor)
        for i in range(pos+1, len(str_dividend)):
            dividend = int(remainder + str_dividend[i])
            # print(dividend)
            quotient, remainder = self.simpleDevide(dividend, divisor)
            res += str(quotient)
            remainder = str(remainder)

        res = int(res)
        ###########################################
        if sign:
            res = 0-res

        if res < -2147483648 or res > 2147483647:
            res = 2147483647

        return res

    def simpleDevide(self, dividend, divisor):
        """
        params: dividend, divisor both are positive numbers
        """
        res = 0
        while dividend >= divisor:
            dividend -= divisor
            res += 1

        return res, dividend


s = Solution()
print(s.simpleDevide(6, 30))
print(s.divide(987654321, 3))
print(s.divide(9, 3))
print(s.divide(21, 3))
print(s.divide(2, 3))
print(s.divide(2**31, 1))
