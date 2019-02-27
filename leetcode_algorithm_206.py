# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return None

        prev = None
        cur = head
        post = cur.next

        while post != None:
            cur.next = prev
            prev = cur
            cur = post
            post = cur.next

        cur.next = prev
        return cur
