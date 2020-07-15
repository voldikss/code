from typing import List


class Solution:
    def grayCode(self, n: int) -> List[int]:
        if n == 0:
            return [0]
        res = ["0" * n]
        for i in range(n, 0, -1):
            for num in res[::-1]:
                res.append("".join((num[: i - 1], "1", num[i:])))

        res = map(lambda x: int(x, 2), res)
        return list(res)


s = Solution()
print(s.grayCode(0))
print(s.grayCode(1))
print(s.grayCode(2))
print(s.grayCode(3))
