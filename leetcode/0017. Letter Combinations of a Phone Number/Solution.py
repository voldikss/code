class Solution:
    def letterCombinations(self, digits):
        if digits == "":
            return []

        m = {
            '1': [''],
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z'],
            '0': ['']
        }

        res = ['']
        for d in digits:
            res = [i+j for j in m[d] for i in res]

        return res

    def letterCombinations_v2(self, digits):
        if not digits:
            return []

        m = {
            '1': [''],
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z'],
            '0': ['']
        }

        def helper(digits, tmp):
            if len(digits) == 1:
                for i in m[digits]:
                    res.append(tmp + i)

            else:
                for i in m[digits[0]]:
                    helper(digits[1:], tmp + i)

        res = []
        helper(digits, '')

        return res


s = Solution()
digits = "233"
res = s.letterCombinations_v2(digits)
print(res)
print(len(res))
