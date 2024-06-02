// 看了官方的解释才写出来的
function longestConsecutive(nums: number[]): number {
  const numSet = new Set(nums)
  let result = 0
  for (const n of numSet) {
    if (numSet.has(n - 1)) {
      continue
    }
    let i = 0
    while (i < numSet.size) {
      if (!numSet.has(n + i)) {
        break
      }
      i++
    }
    result = Math.max(result, i)
  }
  return result
}
