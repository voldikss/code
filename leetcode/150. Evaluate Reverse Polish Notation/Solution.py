class Solution:
    def evalRPN(self, tokens):
        stack = []
        for t in tokens:
            if t not in ['+', '-', '*', '/']:
                stack.append(t)
            else:
                n = stack.pop()
                m = stack.pop()
                tmp = eval(m+t+n)
                if t == '/':
                    tmp = int(tmp)
                # print(m+t+n)
                stack.append(str(tmp))

        return stack[0]


samples = [
    ["2", "1", "+", "3", "*"],
    ["4", "13", "5", "/", "+"],
    ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"],
]
s = Solution()
for i in samples:
    print(s.evalRPN(i))
