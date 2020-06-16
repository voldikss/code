class Automation:
    def __init__(self, text):
        self.text = text
        self.pos = 0
        if len(self.text) == 0:
            self.current_char = None
        else:
            self.current_char = self.text[self.pos]

        self.result = ""
        self.sign = 1

    def advance(self):
        self.pos += 1
        if self.pos > len(self.text) - 1:
            self.current_char = None
        else:
            self.current_char = self.text[self.pos]

    def start(self):
        if self.current_char is not None:
            if self.current_char.isspace():
                self.advance()
                self.start()
            elif self.current_char.isdigit():
                self.in_number()
            elif self.current_char == "+" or self.current_char == "-":
                self.signed()

    def signed(self):
        if self.current_char == "+":
            self.sign = 1
            self.advance()
        elif self.current_char == "-":
            self.sign = -1
            self.advance()
        if self.current_char is not None and self.current_char.isdigit():
            self.in_number()

    def in_number(self):
        if self.current_char is not None and self.current_char.isdigit():
            self.result += self.current_char
            self.advance()
            self.in_number()


# text = "    -12 34abcd"
# text = '-12345'
# s = Automation(text)
# s.start()

#
class Solution:
    def myAtoi(self, str: str) -> int:
        s = Automation(str)
        s.start()
        if s.result != "":
            n = s.sign * int(s.result)
            if n > 2 ** 31 - 1:
                return 2 ** 31 - 1
            elif n < -(2 ** 31):
                return -(2 ** 31)
            else:
                return n
        else:
            return 0


s = Solution()
print(s.myAtoi(""))
