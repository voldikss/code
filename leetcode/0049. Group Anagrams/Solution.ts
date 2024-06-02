function groupAnagrams(strs: string[]): string[][] {
    const groups = new Map<string, string[]>()
    for (let i = 0; i < strs.length; i++) {
        // calculate hash key
        const word = strs[i]
        // let hashKey = 0
        // for (const letter of word) {
        //     hashKey |= 1 << (letter.charCodeAt(0) - 'a'.charCodeAt(0))
        // }
        // console.log(word, hashKey)
        const hashKey = word.split('').sort().join('')
        if (groups.has(hashKey)) {
            groups.get(hashKey)!.push(word)
        } else {
            groups.set(hashKey, [word])
        }
    }
    return [...groups.values()]
};
