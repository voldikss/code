class Solution:
    def linearEquation(self, equation1, equation2):
        a1, b1, c1 = self.parse(equation1)
        a2, b2, c2 = self.parse(equation2)
        x = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1)
        y = (c1 * a2 - a1 * c2) / (b1 * a2 - a1 * b2)
        return [x, y]

    def parse(self, equation):
        left, right = equation.split("=")
        a_left, b_left, c_left = self.parse_coef(left)
        a_right, b_right, c_right = self.parse_coef(right)
        a = a_left - a_right
        b = b_left - b_right
        c = c_right - c_left
        return a, b, c

    def parse_coef(self, expr):
        import re

        res = re.findall(r"-*\d*[xy]{0,1}", expr)
        a = 0
        b = 0
        c = 0
        for m in res:
            if m == "":
                continue
            if m == "x":
                a += 1
            elif m == "-x":
                a -= 1
            elif m == "y":
                b += 1
            elif m == "-y":
                b -= 1
            elif m[-1] == "x":
                a += int(m[:-1])
            elif m[-1] == "y":
                b += int(m[:-1])
            else:
                c += int(m)
        print(expr)
        print(a, b, c)
        return a, b, c


s = Solution()
# res = s.linearEquation("x+3y=9", "2x+y=13")
res = s.linearEquation("6x-7+3y=2+5x", "-5+x+y=8-x")
print(res)
