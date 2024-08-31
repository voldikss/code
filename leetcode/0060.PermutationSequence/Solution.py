from typing import List


class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        def helper(k: int, index: int):
            if index == n:
                return

            for i in range(1, n + 1):
                if used[i]:
                    continue
                cnt = factorial[n - index - 1]
                if k > cnt:
                    k -= cnt
                    continue

                used[i] = True
                path.append(i)
                helper(k, index + 1)

        used = [False for _ in range(0, n + 1)]
        factorial = [1 for _ in range(n + 1)]
        for i in range(2, n + 1):
            factorial[i] = i * factorial[i - 1]

        path = []
        helper(k, 0)
        return "".join([str(i) for i in path])


s = Solution()
print(s.getPermutation(3, 3))
# print(s.getPermutation(4, 9))
