function findAnagrams(s: string, p: string): number[] {
  let start = 0
  let end = p.length - 1
  const result: number[] = []
  const matcher = getMatcher(p)
  while (end < s.length) {
    if (matcher(s.slice(start, end + 1))) {
      result.push(start)
      start++
      end++
    } else {
      // start = end + 1
      start++
      end = start + p.length - 1
    }
  }
  return result
}

function getMatcher(target: string) {
  const targetLetterArray = new Array(26).fill(0)
  for (const l of target) {
    targetLetterArray[l.charCodeAt(0) - 'a'.charCodeAt(0)]++
  }
  return (substring: string) => {
    // console.log(substring)
    const letterArray = new Array(26).fill(0)
    for (const l of substring) {
      letterArray[l.charCodeAt(0) - 'a'.charCodeAt(0)]++
    }
    // console.log(targetLetterArray)
    // console.log(letterArray)
    for (let i = 0; i < letterArray.length; i++) {
      if (letterArray[i] !== targetLetterArray[i]) {
        return false
      }
    }
    return true
  }
}
