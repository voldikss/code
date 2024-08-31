/**
 Do not return anything, modify nums in-place instead.
 */
function moveZeroes(nums: number[]): void {
  let start = nums.findIndex((x) => x === 0)
  let end = start
  if (start < 0) return
  // console.log({start, end})
  while (end < nums.length - 1) {
    while (end < nums.length - 1 && nums[end + 1] === 0) {
      end++
    }
    moveChunk(nums, start, end)
    start++
    end++
  }
}

function moveChunk(nums: number[], start: number, end: number) {
  if (end >= nums.length - 1) return
  const temp = nums[start]
  nums[start] = nums[end + 1]
  nums[end + 1] = temp
}

/**
0 1 0  3 0 12
1 0 0  3 0 12
1 3 0  0 0 12
1 3 12 0 0 0
 */
