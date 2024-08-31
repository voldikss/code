class Solution:
    def matrixScore(self, A):
        r = len(A)
        c = len(A[0])
        for ri in range(r):
            if A[ri][0] != 1:
                for ci in range(c):
                    A[ri][ci] = 1 - A[ri][ci]

        for ci in range(c):  # todo
            cnt1 = sum([A[ri][ci] == 1 for ri in range(r)])
            cnt0 = r - cnt1
            if (cnt1 < cnt0):
                for ri in range(r):
                    A[ri][ci] = 1 - A[ri][ci]

        # print(A)

        res = 0
        for ri in range(r):
            for ci in range(c):
                res += A[ri][c-1-ci] * 2 ** ci

        return res


s = Solution()
input = [[0, 0, 1, 1], [1, 0, 1, 0], [1, 1, 0, 0]]
ans = s.matrixScore(input)
print(ans)
