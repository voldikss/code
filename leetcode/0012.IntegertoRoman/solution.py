class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        romanTable = {1: "I", 2: "II", 3: "III", 4: "IV", 5: "V", 6: "VI", 7: "VII", 8: "VIII", 9: "IX", 10: "X"}
        
        if num in romanTable:
            return romanTable[num]
        
        romanStr = ""
        m = num // 1000
        m_remainder = num % 1000
        c = m_remainder // 100
        c_remainder = m_remainder % 100
        x = c_remainder // 10
        x_remainder = c_remainder % 10
        
        romanStr += "M" * m
        if c == 9:
            romanStr += "CM"
        elif c == 4:
            romanStr += "CD"
        elif c >= 5:
            romanStr += "D" + "C" * (c - 5)
        else:
            romanStr += "C" * c
        if x == 9:
            romanStr += "XC"
        elif x == 4:
            romanStr += "XL"
        elif x >= 5:
            romanStr += "L" + "X" * (x - 5)
        else:
            romanStr += "X" * x
        if x_remainder:
            romanStr += romanTable[x_remainder]
        
        return romanStr


int1 = 3
int2 = 58
int3 = 60
s = Solution()
print(s.intToRoman(int1))
print(s.intToRoman(int2))
print(s.intToRoman(int3))
