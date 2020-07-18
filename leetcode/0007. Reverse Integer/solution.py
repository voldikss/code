class Solution:
    def reverse(self, x):
        r = 0
        xx = abs(x)
        while xx:
            r = r * 10 + xx % 10
            xx = xx // 10
        if abs(r) > 2 ** 31 - 1:
            return 0
        if x > 0:
            print(r)
            return r
        else:
            print(-r)
            return -r
