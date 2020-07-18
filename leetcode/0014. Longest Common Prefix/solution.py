class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 1:
            return strs[0]
        if len(strs) == 0:
            return ""
        prefix = ""
        firstStr = strs[0]
        for i in range(len(firstStr)):
            for word in strs:
                if i >= len(word) or word[i] != firstStr[i]:
                    return prefix
            prefix += firstStr[i]
        
        return prefix


strs1 = ["flower", "flow", "flight"]
strs2 = ["dog", "racecar", "car"]

s = Solution()
print(s.longestCommonPrefix(strs1))
print(s.longestCommonPrefix(strs2))
