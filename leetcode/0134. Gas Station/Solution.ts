/**
 * 遍历 +  优化
 */
function canCompleteCircuit(gas: number[], cost: number[]): number {
  for (let i = 0; i < gas.length; i++) {
    let gasRemain = gas[i]
    let j = i
    /**
     * 不好的做法：
     * let gasRemain = 0
     * while (gasRemain >= 0) {
     *   gasRemain -= cost[j]
     *   gasRemain += gas[j]
     * }
     * 更好的做法应该是将 “是否能继续走” 的条件写到 while () 里面
     * 即 while (gasRemain - cost[j] >= 0) {
     */
    while (gasRemain - cost[j] >= 0) {
      gasRemain -= cost[j]
      gasRemain += gas[(j + 1) % gas.length]
      // console.log(i, gasRemain)
      j = (j + 1) % gas.length
      if (j === i) {
        return i
      }
    }
    if (i > j) {
      return -1
    }
    i = j
  }
  return -1
}
