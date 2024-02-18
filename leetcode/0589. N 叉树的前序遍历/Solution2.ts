/**
 * Definition for node.
 * class Node {
 *     val: number
 *     children: Node[]
 *     constructor(val?: number) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.children = []
 *     }
 * }
 */

function preorder(root: Node | null): number[] {
  const stack: Node[] = []
  stack.push(root)

  const result: number[] = []

  while (stack.length) {
    const currNode = stack.pop()
    if (!currNode) break
    result.push(currNode.val)
    for (const child of currNode.children.reverse()) {
      stack.push(child)
    }
  }
  return result
}
