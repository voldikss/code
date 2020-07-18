from typing import List


class Solution:
    def grayCode(self, n: int) -> List[int]:
        res = [0]
        for i in range(n):
            res += map(lambda x: x + 2 ** i, res[::-1])

        return res


s = Solution()
print(s.grayCode(0))
print(s.grayCode(1))
print(s.grayCode(2))
print(s.grayCode(3))
