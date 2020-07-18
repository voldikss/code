class Solution:
    def removeDuplicateLetters(self, s):
        stack = []
        for i, ch in enumerate(s):
            ch = s[i]
            # print(stack, len(stack) > 0, len(stack) > 0 and stack[-1] > ch, s.rfind(ch))
            if ch in stack:
                continue
            while len(stack) > 0 and stack[-1] > ch and s.rfind(stack[-1]) > i:
                stack.pop()
            stack.append(ch)

        return ''.join(stack)
        # print(stack)


s = Solution()
s.removeDuplicateLetters("cbacdcbc")
