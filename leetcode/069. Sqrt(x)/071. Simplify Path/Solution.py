class Solution:
    def simplifyPath(self, path: str) -> str:
        l = path.split("/")
        res = []
        for i in l:
            if i == "..":
                if res:
                    res.pop()
            elif i and i != ".":
                res.append(i)

        return "/" + "/".join(res)


s = Solution()
print(s.simplifyPath("/home"))
print(s.simplifyPath("/home/"))
print(s.simplifyPath("/../"))
print(s.simplifyPath("/home/voldikss/./Applications/../dotfiles"))
print(s.simplifyPath("/home//foo/"))
print(s.simplifyPath("/a/../../b/../c//.//"))
