function lengthOfLongestSubstring(s: string): number {
  if (s.length === 0) return 0
  let result = 1
  const letters = new Set()
  let j = 0
  for (let i = 0; i < s.length; i++) {
    if (i !== 0) {
      letters.delete(s[i - 1])
    }
    // let j = i + 1
    while (!letters.has(s[j]) && j < s.length) {
      letters.add(s[j])
      j++
    }
    result = Math.max(result, j - i)
  }
  return result
}
