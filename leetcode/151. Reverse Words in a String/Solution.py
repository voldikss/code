class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()
        stack = []
        res = ''
        for i in range(len(s), 0, -1):
            c = s[i-1]
            if c == ' ':
                if not stack:
                    continue
                while stack:
                    res += stack.pop()
                res += ' '
            else:
                stack.append(c)
        while stack:
            res += stack.pop()

        return res


samples = [
    "the sky is blue",
    "  hello world!  ",
    "a good   example",
    "a",
    "",
    "   abc   def  "
]
s = Solution()
for i in samples:
    print(s.reverseWords(i))
