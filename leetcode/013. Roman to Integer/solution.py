class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        """
        从后往前便利相加，不怎么优雅
        """
        romanTable = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
        num = 0
        for i in range(len(s) - 1, -1, -1):
            if (i + 1 < len(s)):
                if s[i] == "I" and (s[i + 1] == "V" or s[i + 1] == "X"):
                    num -= 1
                elif s[i] == "X" and (s[i + 1] == "L" or s[i + 1] == "C"):
                    num -= 10
                elif s[i] == "C" and (s[i + 1] == "D" or s[i + 1] == "M"):
                    num -= 100
                else:
                    num += romanTable[s[i]]
            else:
                num += romanTable[s[i]]
        
        return num


class Solution2:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        """
        看了下数目最多的，比较优雅
        """
        romanTable = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
        num = 0
        i = 0
        while i < len(s):
            # 比较关键了
            if i + 1 < len(s) and romanTable[s[i]] < romanTable[s[i + 1]]:
                num += romanTable[s[i + 1]] - romanTable[s[i]]
                i += 2
            else:
                num += romanTable[s[i]]
                i += 1
        return num


romanStr1 = "MCMXCIV"

s = Solution2()
print(s.romanToInt(romanStr1))
