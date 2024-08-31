function longestConsecutive(nums: number[]): number {
  const normalized = [...new Set(nums).values()].sort((x, y) => x - y)
  if (normalized.length === 0) return 0
  if (normalized.length === 1) return 1
  let start = 0
  let end = 1
  let result = 0
  while (end < normalized.length) {
    if (normalized[end] - 1 !== normalized[end - 1]) {
      start = end
    }
    end++
    result = Math.max(result, end - start)
  }
  return result
}
