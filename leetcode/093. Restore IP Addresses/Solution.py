from typing import List


class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = set()
        for i in range(1, 4):
            for j in range(1, 4):
                for k in range(1, 4):
                    for _ in range(1, 4):
                        a = s[:i]
                        b = s[i : i + j]
                        c = s[i + j : i + j + k]
                        d = s[i + j + k :]
                        if a == "":
                            continue
                        if b == "":
                            continue
                        if c == "":
                            continue
                        if d == "":
                            continue
                        if len(a) > 1 and a[0] == "0":
                            continue
                        if len(b) > 1 and b[0] == "0":
                            continue
                        if len(c) > 1 and c[0] == "0":
                            continue
                        if len(d) > 1 and d[0] == "0":
                            continue
                        if int(a) > 255:
                            continue
                        if int(b) > 255:
                            continue
                        if int(c) > 255:
                            continue
                        if int(d) > 255:
                            continue
                        res.add(".".join([a, b, c, d,]))
        return list(res)


s = Solution()
# print(s.restoreIpAddresses("0000"))
print(s.restoreIpAddresses("010010"))
# print(s.restoreIpAddresses("25525511135"))
