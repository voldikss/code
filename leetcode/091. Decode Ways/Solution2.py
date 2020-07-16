class Solution:
    def numDecodings(self, s: str) -> int:
        def helper(ss, start):
            if start == len(ss) - 1:
                if ss[start] == "0":
                    return 0
                else:
                    return 1
            elif start > len(ss) - 1:
                return 1
            else:
                if ss[start] == "0":
                    return 0
                if start in mem:
                    return mem[start]
                ans1 = helper(ss, start + 1)
                ans2 = 0
                if ss[start : start + 2] <= "26":
                    ans2 = helper(ss, start + 2)
                mem[start] = ans1 + ans2
                return ans1 + ans2

        mem = dict()
        return helper(s, 0)


s = Solution()
print(s.numDecodings("12"))
print(s.numDecodings("226"))
print(s.numDecodings("0"))
print(s.numDecodings("00"))
print(s.numDecodings("000"))
print(s.numDecodings("205"))
print(s.numDecodings("2005"))
