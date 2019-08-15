class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if s == s[::-1]:
            return s
        
        if not s:
            return ''
        
        res = ""
        for i in range(len(s)):
            pEven = self.findPalindrome(s, i, i + 1)
            if len(pEven) > len(res):
                res = pEven
            pOdd = self.findPalindrome(s, i, i)
            if len(pOdd) > len(res):
                res = pOdd
        return res
    
    def findPalindrome(self, s, l, r):
        p = ""
        while l >= 0 and r < len(s) and s[l] == s[r]:
            if len(s[l:r + 1]) > len(p):
                p = s[l:r + 1]
            l -= 1
            r += 1
        return p


s = Solution()
s1 = "babad"
s2 = "cbbd"
s3 = "bb"
print(s.longestPalindrome(s1))
print(s.longestPalindrome(s2))
print(s.longestPalindrome(s3))
