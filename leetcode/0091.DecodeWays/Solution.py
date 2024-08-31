class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == "0":
            return 0

        dp = [0] * (len(s) + 1)
        dp[0] = 1
        dp[-1] = 1 # python: lol!
        for i in range(1, len(s)):
            if s[i] == "0":
                if s[i - 1] == "1" or s[i - 1] == "2":
                    dp[i] = dp[i - 2]
                else:
                    return 0
            elif s[i] <= "6":
                if s[i - 1] == "1" or s[i - 1] == "2":
                    dp[i] = dp[i - 1] + dp[i - 2]
                else:
                    dp[i] = dp[i - 1]
            else:
                if s[i - 1] == "1":
                    dp[i] = dp[i - 1] + dp[i - 2]
                else:
                    dp[i] = dp[i - 1]

        return dp[len(s) - 1]


s = Solution()
print(s.numDecodings("12"))
print(s.numDecodings("226"))
print(s.numDecodings("0"))
print(s.numDecodings("00"))
print(s.numDecodings("000"))
print(s.numDecodings("205"))
print(s.numDecodings("2005"))
