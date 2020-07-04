class Solution:
    def simplifyPath(self, path: str) -> str:
        l = path.split("/")
        # print(l)
        res = [""]
        for i in l:
            if i != "":
                res.append(i)
            if i == ".":
                res.pop()
            elif i == "..":
                if len(res) > 1:
                    res.pop()
                if len(res) > 1:
                    res.pop()

        while len(res) > 1 and res[-1] == "":
            res.pop()
        if len(res) == 0:
            res.append("")
        if len(res) == 1 and res[0] == "":
            res.append("")
        # res.append('')
        print(res)
        return "/".join(res)


s = Solution()
print(s.simplifyPath("/home"))
print(s.simplifyPath("/home/"))
print(s.simplifyPath("/../"))
print(s.simplifyPath("/home/voldikss/./Applications/../dotfiles"))
print(s.simplifyPath("/home//foo/"))
print(s.simplifyPath("/a/../../b/../c//.//"))
