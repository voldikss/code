class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        paren = {
            '(': ')',
            '[': ']',
            '{': '}'
        }
        for i in s:
            if i in paren:
                stack.append(i)
                continue
            # stack cannot be empty
            if stack and i == paren[stack.pop()]:
                continue
            else:
                return False
        # if stack is not empty, return False
        return not stack


class Solution2:
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            if c == '(':
                stack.append(')')
            elif c == '[':
                stack.append(']')
            elif c == '{':
                stack.append('}')
            elif (not stack) or c != stack.pop():
                return False

        return not stack


s = Solution2()
res = s.isValid('()')
print(res)
