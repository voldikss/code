class Solution:
    def generateParenthesis(self, n):
        def helper(paren=[]):
            if len(paren) == 2*n:
                if isValid(paren):
                    res.append(''.join(paren))
            else:
                paren.append('(')
                helper(paren)
                paren.pop()
                paren.append(')')
                helper(paren)
                paren.pop()

        def isValid(paren):
            bal = 0
            for i in paren:
                if i == '(':
                    bal += 1
                else:
                    bal -= 1
                if bal < 0:
                    return False
            return bal == 0

        res = []
        helper()
        return res

    def generateParenthesis_v2(self, n):
        # TODO
        ...


s = Solution()
res = s.generateParenthesis(3)
print(res)
