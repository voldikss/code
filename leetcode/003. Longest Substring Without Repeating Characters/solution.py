class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        """
        算法1: 最朴素的想法。最优化，800ms
        """
        maxL = 0
        for i in range(len(s)):
            for j in range(i, len(s)):
                if not s[j] in s[i:j]:
                    if j + 1 - i > maxL:
                        maxL = j + 1 - i
                else:
                    break
        return maxL


class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        position = {}
        start = 0
        maxL = 0
        for i, j in enumerate(s):
            if j in position and position[j] >= start:
                start = position[j] + 1
                position[j] = i
            position[j] = i
            
            if i - start + 1 > maxL:
                maxL = i - start + 1
        
        return maxL


s1 = "abcabcbb"
s2 = "bbbbb"
s3 = "pwwkew"
s4 = ""
s5 = " "
s6 = "a"
s7 = "ab"
s8 = "abca"

s = Solution2()
print(s.lengthOfLongestSubstring(s1))
print(s.lengthOfLongestSubstring(s2))
print(s.lengthOfLongestSubstring(s3))
print(s.lengthOfLongestSubstring(s4))
print(s.lengthOfLongestSubstring(s5))
print(s.lengthOfLongestSubstring(s6))
print(s.lengthOfLongestSubstring(s7))
print(s.lengthOfLongestSubstring(s8))
