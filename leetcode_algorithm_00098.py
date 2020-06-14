# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.isValid(root, None, None)

    def isValid(self, root, floor, ceiling):
        if None == root:
            return True
        if None != root.left:
            if root.left.val >= root.val or (floor != None and root.left.val <= floor):
                return False
        if None != root.right:
            if root.right.val <= root.val or (ceiling != None and root.right.val >= ceiling):
                return False

        return self.isValid(root.left, floor, root.val) and self.isValid(root.right, root.val, ceiling)
