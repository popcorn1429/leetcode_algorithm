# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root == None:
            return True
        return self.isTreeSymmetric(root.left, root.right)

    def isTreeSymmetric(self, lTree, rTree):
        if lTree == None and rTree == None:
            return True
        if lTree == None or rTree == None:
            return False
        return lTree.val == rTree.val and self.isTreeSymmetric(lTree.left, rTree.right) and self.isTreeSymmetric(lTree.right, rTree.left)
