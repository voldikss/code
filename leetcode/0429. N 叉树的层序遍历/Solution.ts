function levelOrder(root: Node | null): number[][] {
  if (!root) return []

  const result: number[][] = []

  const queue: Node[][] = []
  queue.push([root])

  while (queue.length > 0) {
    const currResult = []
    const currNodes = queue.shift()
    const nextNodes: Node[] = []
    for (const currNode of currNodes ?? []) {
      currResult.push(currNode.val)
      for (const child of currNode.children) {
        nextNodes.push(child)
      }
    }
    if (nextNodes.length > 0) {
      queue.push(nextNodes)
    }
    if (currResult.length > 0) {
      result.push(currResult)
    }
  }
  return result
}
