from typing import List
import sys


# 看了 https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/ 的解法
# 但是没有采用 虚拟加数 的做法
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        if m > n:
            return self.findMedianSortedArrays(nums2, nums1)

        # 如果总共是偶数个，割的左边有一半，右边有一半
        # 如果总共是奇数个，割的右边比左边多一个，最后取的时候取 rmin_1 和 rmin_2 较小的那个
        s = (m + n) // 2
        if (m + n) % 2 == 1:
            odd = True
        else:
            odd = False

        lo, hi = 0, m
        while lo <= hi:
            # 此处 (lo + (hi -1)) // 2，必须是 (hi-1)，否则样例 ([1,3],[2]) 过不了
            # 因为 (0+1)//2 和 (0+0)//2 的结果是一样的，但是又不能在初始化 hi 的时候令 hi = m-1
            # 那样子 while 这里就会直接跳过(lo = 0, hi = 1-1 = 0), 只循环一遍，下一次 hi=-1时就不符合条件了
            c1 = (lo + hi - 1) // 2
            c2 = s - c1 - 1 - 1

            if c1 >= 0:
                lmax_1 = nums1[c1]
            else:
                lmax_1 = -sys.maxsize
            if c1 + 1 < m:
                rmin_1 = nums1[c1 + 1]
            else:
                rmin_1 = sys.maxsize

            if c2 >= 0:
                lmax_2 = nums2[c2]
            else:
                lmax_2 = -sys.maxsize
            if c2 + 1 < n:
                rmin_2 = nums2[c2 + 1]
            else:
                rmin_2 = sys.maxsize

            if lmax_2 > rmin_1:
                lo += 1
            elif lmax_1 > rmin_2:
                hi -= 1
            else:
                break

        print(lmax_1, rmin_1, lmax_2, rmin_2)
        # 如果是奇数，取 rmin_1 和 rmin_2 最小的
        if odd:
            return float(min(rmin_2, rmin_1))
        else:
            return (max(lmax_2, lmax_1) + min(rmin_2, rmin_1)) / 2.0


s = Solution()
assert s.findMedianSortedArrays([1, 3], [2]) == 2.0
assert s.findMedianSortedArrays([1, 2], [3, 4]) == 2.5
assert s.findMedianSortedArrays([1, 4, 7, 9], [2, 3, 5]) == 4
assert s.findMedianSortedArrays([1, 4, 7, 9], [2, 3, 4, 5]) == 4
