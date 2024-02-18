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
  if (!root) return []
  if (!root.children.length) return [root.val]
  const result: number[] = []
  result.push(root.val)
  for (const child of root.children) {
    result.push(...preorder(child))
  }
  return result
};
