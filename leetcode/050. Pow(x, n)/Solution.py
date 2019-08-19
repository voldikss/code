def quickPow(x, n):
    """x > 0, n > 0"""
    ans = 1
    while n:
        if n & 1:
            ans *= x
        x *= x
        n >>= 1
    return ans


class Solution:
    def myPow(self, x, n):
        sign_x = 1
        sign_n = 1
        if x < 0:
            if n % 2 == 1:
                sign_x = -1

        if n < 0:
            sign_n = -1

        x = abs(x)
        n = abs(n)
        ans = quickPow(x, n)
        if sign_x < 0:
            ans = -ans

        if sign_n < 0:
            ans = 1/ans

        print(ans)
        return ans


s = Solution()
s.myPow(2, 4)
