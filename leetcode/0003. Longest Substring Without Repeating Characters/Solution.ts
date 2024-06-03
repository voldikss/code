function lengthOfLongestSubstring(s: string): number {
  if (s.length === 0) return 0
  if (s.length === 1) return 1
  let result = 1
  let start = 0
  let end = 0
  const letters = new Map()
  while (end < s.length) {
    // 遇到重复的了
    if (letters.has(s[end])) {
      // 将 start 跳到重复第一个重复字母之后
      // 这里需要先将从原 start 到第一个重复字母之间的都清理掉
      for (let i = start; i < letters.get(s[end]); i++) {
        letters.delete(s[i])
      }
      start = letters.get(s[end]) + 1
      // 如果下一次还是重复的，一直往后走
      while (start < end && s[start] === s[end]) {
        start++
      }
      letters.delete(s[end])
      // if (start === end) end++
      // end++
    } else {
      letters.set(s[end], end)
      end++
      // console.log({start, end})
      result = Math.max(result, end - start)
    }
  }
  return result
}
