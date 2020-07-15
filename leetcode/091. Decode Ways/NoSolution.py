# TLE...
class Solution:
    def numDecodings(self, s: str) -> int:
        def helper(ss):
            nonlocal res
            if ss[0] == "0":
                return
            if len(ss) == 1:
                res += 1
            elif len(ss) == 2:
                if ss[0] == "0":
                    return
                if ss <= "26":
                    if ss[1] == "0":
                        res += 1
                    else:
                        res += 2
                else:
                    if ss[1] != "0":
                        res += 1
            else:
                helper(ss[1:])
                if ss[:2] <= "26":
                    helper(ss[2:])

        res = 0
        helper(s)
        return res


s = Solution()
# print(s.numDecodings("12"))
# print(s.numDecodings("226"))
# print(s.numDecodings("0"))
# print(s.numDecodings("00"))
# print(s.numDecodings("000"))
# print(s.numDecodings("205"))
# print(s.numDecodings("2005"))
# print(s.numDecodings("9355141842519423434975558424574331479338913773268525913972842463395324957127519863135646135786662832"))
print(s.numDecodings("6579116298432278845622761755757279557188173828512818893993886417157678271875796685375772244734739778"))
