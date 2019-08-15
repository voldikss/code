# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if not l1 or not l2: return l1 or l2
        n1 = 0
        n2 = 0
        
        mul1 = 1
        while l1:
            n1 += l1.val * mul1
            l1 = l1.next
            mul1 *= 10
        
        mul2 = 1
        while l2:
            n2 += l2.val * mul2
            l2 = l2.next
            mul2 *= 10
        
        # Not good
        # result = list(map(int,list(str(n1+n2)[::-1])))
        
        n = n1 + n2
        if n == 0:
            return ListNode(0)
        lst = []
        while n:
            lst.append(n % 10)
            n = n // 10
        
        result = ListNode(lst[0])
        temp = result
        for i in lst[1:]:
            current_node = ListNode(i)
            temp.next = current_node
            temp = current_node
        
        return result
