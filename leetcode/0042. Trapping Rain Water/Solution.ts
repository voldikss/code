function trap(height: number[]): number {
  const maxLeft = new Array(height.length).fill(0)
  const maxRight = new Array(height.length).fill(0)
  for (let i = 1; i < height.length; i++) {
    maxLeft[i] = Math.max(maxLeft[i - 1], height[i - 1])
  }
  for (let i = height.length - 2; i >= 0; i--) {
    maxRight[i] = Math.max(maxRight[i + 1], height[i + 1])
  }
  console.log(maxLeft)
  console.log(maxRight)
  let sum = 0
  for (let i = 0; i < height.length; i++) {
    sum += Math.max(Math.min(maxLeft[i], maxRight[i]) - height[i], 0)
  }
  return sum
}
