from collections import defaultdict


class Solution:
    def firstUniqChar(self, s: str) -> int:
        hashmap = defaultdict(int)
        for c in s:
            hashmap[c] += 1

        for idx in range(len(s)):
            c = s[idx]
            print(c)
            if hashmap[c] == 1:
                return idx
        return -1


samples = [
    "leetcode",
    "loveleetcode",
    "dddccdbba"
]
s = Solution()
for i in samples:
    print(s.firstUniqChar(i))
