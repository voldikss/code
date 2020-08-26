# 套路等

## 数组类

- 双指针
- 倒着来
- 先排序

## 链表类

- 如果超时，检查是不是尾部没有指向 `nullptr`
- 新建指针变量，记得显示赋值为 `nullptr`

## 二叉树

- 层序遍历时获取当前层数：使用 `q.size()`，见 [LeetCode 103](./leetcode/0103. Binary Tree Zigzag Level Order Traversal)

## 易错

- 多重循环，检查循环变量是否重名（i,j,k）

## 回溯

- 超时的话首先考虑使用 memorization,构造 cache 时，不一定需要 map，有时候可以直接用数组([LeetCode 139](./leetcode/0139. Word Break/Solution.cpp))

- 改动态规划

## 要求常数空间

- 原地修改，利用已有的空间
- 多指针，如快慢指针等
