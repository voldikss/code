from collections import defaultdict
import copy


class Solution:
    def countCharacters(self, words, chars):
        res = 0
        hash_map = defaultdict(int)
        for c in chars:
            hash_map[c] += 1

        for w in words:
            m = copy.deepcopy(hash_map)
            for c in w:
                if c in m and m[c] > 0:
                    m[c] -= 1
                else:
                    break
            else:
                res += len(w)

        # print(res)
        return res


s = Solution()
words = ["hello", "world", "leetcode"]
chars = "welldonehoneyr"
s.countCharacters(words, chars)
