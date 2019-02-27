# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        elements = []
        curNode = head
        while curNode != None:
            elements.append(curNode.val)
            curNode = curNode.next

        totalCount = len(elements)
        if totalCount < 2:
            return True
        for i in range(0, totalCount/2+1):
            if elements[i] != elements[totalCount-1-i]:
                return False
        return True