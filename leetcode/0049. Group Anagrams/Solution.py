class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        res = {}
        for s in strs:
            id = [0] * 26
            for c in s:
                id[ord(c) - 97] += 1
            key = tuple(id)
            if key in res:
                res[key].append(s)
            else:
                res[key] = [s]
        return res.values()


s = Solution()
print(s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
