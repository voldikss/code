// 没过
function threeSum(nums: number[]): number[][] {
  nums = nums.sort((x, y) => x - y)
  // console.log(nums)
  const map = new Map<number, number[]>()
  const result: number[][] = []
  const cache = new MultiMap()
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > 0) break
    for (let j = i + 1; j < nums.length; j++) {
      if (map.has(nums[j])) {
        const indexes = map.get(nums[j])!
        if (indexes.includes(j)) continue
        const values = indexes.map((x) => nums[x])
        if (cache.has(values)) continue
        // console.log(values)
        result.push([...values, nums[j]])
        cache.set(values, true)
      } else {
        map.set(-(nums[i] + nums[j]), [i, j])
      }
    }
  }
  return result
}

class MultiMap {
  private kv = new Map()

  set(keys: any[], value: any) {
    this.kv.set(keys.join(), value)
  }

  get(...keys: any[]) {
    return this.kv.get(keys.join())
  }

  has(...keys: any[]) {
    return this.kv.has(keys.join())
  }
}
