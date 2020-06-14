# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """

        def getTree(nums, start, end)->TreeNode:
            if start == end:
                return None
            #pos = int((start+end)/2)
            pos = (start+end)//2
            root = TreeNode(nums[pos])
            root.left = getTree(nums, start, pos)
            root.right = getTree(nums, pos+1, end)
            return root

        n = len(nums)
        return getTree(nums, 0, n)
