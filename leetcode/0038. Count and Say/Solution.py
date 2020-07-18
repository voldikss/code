class Solution:
    # my ugly solution...
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        prev_s = self.countAndSay(n-1)

        if len(prev_s) == 1:
            return "1" + str(prev_s)

        curr_s = ""
        count = 1
        for i in range(len(prev_s)-1):
            if prev_s[i] == prev_s[i+1]:
                count += 1
            else:
                curr_s += str(count) + prev_s[i]
                count = 1

        # 相较于下面的写法，这个写法把 i == len(prev_s) - 2 的判定及其部分移除了循环块
        # 因为只需要判断 count 是不是大于1即可，既然跳出循环了就只需要按照 count 进行处理就行了
        if count > 1:
            curr_s += str(count) + prev_s[i+1]
        else:
            curr_s += "1" + prev_s[i+1]

        return curr_s

# class Solution:
#     # my ugly solution...
#     def countAndSay(self, n: int) -> str:
#         if n == 1:
#             return "1"
#         prev_s = self.countAndSay(n-1)

#         if len(prev_s) == 1:
#             return "1" + str(prev_s)

#         curr_s = ""
#         count = 1
#         for i in range(len(prev_s)-1):
#             if prev_s[i] == prev_s[i+1]:
#                 count += 1
#             else:
#                 curr_s += str(count) + prev_s[i]
#                 count = 1
#             if i == len(prev_s) - 2:
#                 if prev_s[i] != prev_s[i+1]:
#                     curr_s += "1" + prev_s[i+1]
#                 else:
#                     curr_s += str(count) + prev_s[i+1]

#         return curr_s


s = Solution()
string = s.countAndSay(7)
print(string)
