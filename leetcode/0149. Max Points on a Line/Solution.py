from collections import defaultdict


class Solution:
    def maxPoints(self, points):
        def check(i, points):
            hashmap = defaultdict(int)
            same = 0
            for j in range(len(points)):
                x0, y0 = points[i][0], points[i][1]
                x, y = points[j][0], points[j][1]
                if i != j:
                    if points[i] == points[j]:
                        same += 1
                        continue

                    # 此处在最后一个样例上会出现精度的问题
                    # 解决方法有三个
                    # 第一，把 dy/dx 换成 dx/dy 比较（只适用于这道题的特殊情况）
                    # 第二，dy*1000/dx
                    # 第三，用最大公约数保存两个数，使用元组保存，这样可以作为 dict 的key
                    dx, dy = x-x0, y-y0
                    if dy == 0:
                        hashmap[float('inf')] += 1
                    else:
                        ration = dy*1000/dx*1000
                        hashmap[ration] += 1

            return same + 1 + (max(hashmap.values()) if hashmap else 0)

        if len(points) == 1:
            return 1

        maxp = 0
        for i in range(len(points)):
            maxp = max(maxp, check(i, points))

        return maxp


s = Solution()
print(s.maxPoints([[1, 1], [2, 2], [3, 3]]))
print(s.maxPoints([[1, 1], [3, 2], [5, 3], [4, 1], [2, 3], [1, 4]]))
print(s.maxPoints([[0, 0]]))
print(s.maxPoints([[0, 0], [0, 0]]))
print(s.maxPoints([[1, 1], [1, 1], [2, 2], [2, 2]]))
print(s.maxPoints([[1, 1], [2, 2], [3, 3]]))
print(s.maxPoints([[0, 0], [94911151, 94911150], [94911152, 94911151]]))
