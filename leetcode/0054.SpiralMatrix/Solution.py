from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if matrix == []:
            return []

        def helper(x, y, m, n):
            # print(x, y, m, n)
            if x > m or y > n:
                return
            if x == m:
                for i in range(y, n + 1):
                    res.append(matrix[x][i])
                return
            if y == n:
                for i in range(x, m + 1):
                    res.append(matrix[i][y])
                return
            for i in range(y, n):
                res.append(matrix[x][i])
            for i in range(x, m):
                res.append(matrix[i][n])
            for i in range(n, y, -1):
                res.append(matrix[m][i])
            for i in range(m, x, -1):
                res.append(matrix[i][x])
            helper(x + 1, y + 1, m - 1, n - 1)

        res = []
        helper(0, 0, len(matrix) - 1, len(matrix[0]) - 1)
        return res


s = Solution()
# print(s.spiralOrder([[1]]))
# print(s.spiralOrder([[1, 2, 3]]))
print(s.spiralOrder([[1], [2], [3]]))
# print(s.spiralOrder([[1, 2, 3], [4, 5, 6], [7, 8, 9]]))
# print(s.spiralOrder([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]))
# print(s.spiralOrder([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]))
