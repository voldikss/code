from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def helper(path, start, target1):
            if target1 == 0:
                res.append(path)
                return
            if target1 < 0 or start == size:
                return

            for i in range(start, size):
                # 这一步去重，不得已看了评论区的解法。
                # 貌似和 ../018. 4Sum 中的用法一样！
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                num = candidates[i]
                tmp = path.copy()
                tmp.append(num)
                helper(tmp, i + 1, target1 - num)

        res = []
        size = len(candidates)
        candidates.sort()
        helper([], 0, target)
        return res


s = Solution()
# print(s.combinationSum2([10, 1, 2, 7, 6, 1, 5], 8))
print(s.combinationSum2([2, 5, 2, 1, 2], 5))
