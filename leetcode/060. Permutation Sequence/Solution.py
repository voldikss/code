from typing import List


class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        count = 0

        def helper(path: str, residual: str):
            nonlocal count
            if len(residual) == 0:
                count += 1
                return path

            for i in range(len(residual)):
                res = helper(path + residual[i], residual[:i] + residual[i + 1 :])
                if count == k:
                    return res

        return helper("", "".join([str(x) for x in range(1, n + 1)]))


s = Solution()
# print(s.getPermutation(3, 3))
print(s.getPermutation(4, 9))
