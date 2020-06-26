# @TODO:
# 这个耗时间也耗空间
# 题解区的解法比这个简介许多
# 有空了去学习一下


class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """

        def helper(start, end):
            if start >= end:
                return
            for i in range(end - start):
                # print(start, end, i)
                (
                    matrix[start][start + i],
                    matrix[start + i][end],
                    matrix[end][end - i],
                    matrix[end - i][start],
                ) = (
                    matrix[end - i][start],
                    matrix[start][start + i],
                    matrix[start + i][end],
                    matrix[end][end - i],
                )
                # pprint(matrix)
            helper(start + 1, end - 1)

        helper(0, len(matrix) - 1)


def pprint(matrix):
    for i in matrix:
        for j in i:
            print("%s\t" % j, end="")
        print()
    print()


# matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
matrix = [[0, 1, 2, 3], [4, 5, 6, 7], [8, 9, 10, 11], [12, 13, 14, 15]]
s = Solution()
s.rotate(matrix)
print(matrix)
