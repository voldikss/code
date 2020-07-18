# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        l = ListNode(0)
        p = l
        while l1 and l2:
            if l1.val < l2.val:
                l.next = l1
                l1 = l1.next
            else:
                l.next = l2
                l2 = l2.next
            l = l.next
        if l1:
            l.next = l1
        elif l2:
            l.next = l2

        return p.next

    def mergeTwoLists2(self, l1: ListNode, l2: ListNode) -> ListNode:
        # ...
        if not l1:
            return l2
        elif not l2:
            return l1

        if l1.val < l2.val:
            l1.next = self.mergeTwoLists2(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists2(l1, l2.next)
            return l2


if __name__ == '__main__':
    l1 = ListNode(1)
    l1.next = ListNode(2)
    l1.next.next = ListNode(4)
    l1.next.next.next = None
    l2 = ListNode(1)
    l2.next = ListNode(2)
    l2.next.next = ListNode(3)
    l2.next.next.next = None
    s = Solution()
    l = s.mergeTwoLists2(l1, l2)
    while l:
        print(l.val)
        l = l.next
